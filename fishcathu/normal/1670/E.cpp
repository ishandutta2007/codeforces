#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=131080;
template<typename T=int>T read(){T x;cin>>x;return x;}

vector<array<int,2>>to[N];
int a[N],b[N],n,cnt;
void dfs(int x,int f)
{
    for(auto [t,i]:to[x])if(t^f)
    {
        ++cnt;
        a[t]=cnt;
        b[i]=cnt^n;
        if(a[x]<n)swap(a[t],b[i]);
        dfs(t,x);
    }
}
void solve()
{
    n=1<<read();
    for(int i=1;i<n;++i)
    {
        int u=read(),v=read();
        to[u].pb({v,i});
        to[v].pb({u,i});
    }
    cnt=0;
    a[1]=n;
    dfs(1,0);
    cout<<"1\n";
    for(int i=1;i<=n;++i)cout<<a[i]<<' ',to[i].clear();
    cout<<'\n';
    for(int i=1;i<n;++i)cout<<b[i]<<' ';
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}