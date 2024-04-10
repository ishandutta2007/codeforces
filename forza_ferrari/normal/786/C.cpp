#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[100001],cnt[100001];
inline int check(int k)
{
    int lst=1,tot=0,ans=1;
    for(int i=1;i<=n;++i)
        if(!cnt[a[i]]++)
        {
            if(tot==k)
            {
                ++ans;
                tot=1;
                for(int j=lst;j<i;++j)
                    --cnt[a[j]];
                lst=i;
            }
            else
                ++tot;
        }
    for(int i=lst;i<=n;++i)
        --cnt[a[i]];
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int maxn=sqrt(n);
    for(int i=1;i<=maxn;++i)
        cout<<check(i)<<" ";
    for(int i=maxn+1,j;i<=n;i=j+1)
    {
        int val=check(i);
        j=i;
        for(int k=20;~k;--k)
            if(j+(1<<k)<=n&&check(j+(1<<k))==val)
                j+=1<<k;
        for(int k=i;k<=j;++k)
            cout<<val<<" ";
    }
    cout<<'\n';
    return 0;
}