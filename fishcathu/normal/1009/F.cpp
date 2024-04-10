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
constexpr int N=1E6+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int son[N],len[N];
int F[N],*f[N],ans[N],*cnt=F;
vector<int>to[N];
void dfs1(int x,int fa)
{
    for(int t:to[x])if(t^fa)
    {
        dfs1(t,x);
        if(cmax(len[x],len[t]))son[x]=t;
    }
    ++len[x];
}
void dfs2(int x,int fa)
{
    ++*(f[x]=++cnt);
    if(!son[x])return;
    dfs2(son[x],x);
    ans[x]=ans[son[x]]+1;
    for(int t:to[x])if(t^fa&&t^son[x])
    {
        dfs2(t,x);
        for(int i=1;i<=len[t];++i)
        {
            f[x][i]+=f[t][i-1];
            if(f[x][i]>f[x][ans[x]]||f[x][i]==f[x][ans[x]]&&i<ans[x])ans[x]=i;
        }
    }
    if(f[x][ans[x]]==1)ans[x]=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;++i)cout<<ans[i]<<'\n';
}