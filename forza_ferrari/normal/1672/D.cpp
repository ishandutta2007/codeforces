#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[200001],b[200001],cnt[200001];
bool vis[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            vis[i]=cnt[i]=0;
        }
        for(int i=1;i<=n;++i)
            cin>>b[i];
        bool flag=1;
        for(int i=1,j=1;i<=n;++i)
        {
            if(j<=n&&a[j]==b[i])
            {
                ++j;
                continue;
            }
            if(cnt[b[i]]&&a[j-1]==b[i])
            {
                --cnt[b[i]];
                continue;
            }
            while(j<=n&&(a[j]^b[i]))
                ++cnt[a[j++]];
            if(j>n)
            {
                flag=0;
                break;
            }
            ++j;
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}