#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[100001],ans;
bool vis[100001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            vis[i]=0;
        }
        int lst=1;
        ans=0;
        for(int i=2;i<=n;++i)
        {
            if(vis[a[i]])
                a[i]=0;
            if(a[i]<a[i-1])
            {
                for(int j=lst;j<i;++j)
                    if(a[j]&&!vis[a[j]])
                    {
                        vis[a[j]]=1;
                        ++ans;
                    }
                lst=i;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}