#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=2E5+10;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N];
vector<int>to[N];
bool vis[N],b[N],ans;
void dfs(int x)
{
    vis[x]=1;
    for(int t:to[x])
    {
        if(vis[t])ans&=b[t];
        else dfs(t);
    }
    b[x]=1;
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        vis[i]=b[i]=0;
        to[i].clear();
    }
    for(int i=1;i<=n;++i)to[a[i]].pb(read());
    int y=0;
    for(int i=1;i<=n;++i)if(to[i].size()>to[y].size())y=i;
    vis[y]=b[y]=ans=1;
    for(int i=1;i<=n;++i)if(!vis[i])dfs(i);
    cout<<(ans?"AC":"WA")<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}