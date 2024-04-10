#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[5001],node[5001],cnt,sum[5001],ans[5001],res;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        for(int j=2;j*j<=abs(a[i]);++j)
            while(a[i]%(j*j)==0)
                a[i]/=j*j;
        node[i]=a[i];
    }
    sort(node+1,node+n+1);
    cnt=unique(node+1,node+n+1)-node-1;
    for(int i=1;i<=n;++i)
        a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            if(!sum[a[j]]++&&node[a[j]])
                ++res;
            ++ans[max(res,1)];
        }
        res=0;
        for(int j=i;j<=n;++j)
            --sum[a[j]];
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}