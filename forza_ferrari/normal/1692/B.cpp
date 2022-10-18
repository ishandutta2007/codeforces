#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
bool vis[10001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=10000;++i)
            vis[i]=0;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            if(!vis[x])
                vis[x]=1;
            else
                ++ans;
        }
        if(ans&1)
            ++ans;
        cout<<n-ans<<'\n';
    }
    return 0;
}