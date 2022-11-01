#include<bits/stdc++.h>
using namespace std;
const int N=1E5+10;
template<typename T=int>T read(){T x;cin>>x;return x;}

const int p=1E9+7;
int a[N],nex[N];
bool b[N],vis[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)b[i]=vis[i]=0;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>nex[a[i]];
    for(int i=1;i<=n;++i)b[read()]=1;
    int ans=1;
    for(int i=1;i<=n;++i)if(!vis[i]&&nex[i]^i)
    {
        bool u=0;
        while(!vis[i])vis[i]=1,u|=b[i],i=nex[i];
        if(!u)ans=ans*2%p;
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}