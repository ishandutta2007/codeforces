#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=1e5+10;
int n,lg,tin[N],cnt,tout[N],id,m,dd[N],d[N];
int f[N][20];
vector<int> ke[N];
vector<pii> ad[N];
vector<int> Q;
void DFS(int u) {
    tin[u] = ++id;
    forinc(i,1,log2(n)) f[u][i]=f[f[u][i-1]][i-1];
    forv(v,ke[u]) if(f[u][0]!=v)
    {
        d[v]=d[u]+1;
        f[v][0]=u;
        DFS(v);
    }
    tout[u]=++id;
}
bool check(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int LCA(int u, int v)
{
    if (check(u, v)) return u;
    if (check(v, u)) return v;
    fordec(i,lg,0) if (f[u][i]&&!check(f[u][i], v)) u = f[u][i];
    return f[u][0];
}
bool cmp(int i, int j)
{
    return tin[i] < tin[j];
}
int top, st[N],dp[N][2],ok=0;
void dfs(int u,int p)
{
    dp[u][1]=dp[u][0]=0;
    if(dd[u]==cnt) dp[u][0]=N;
    int M=0,F=0;
    forv(v,ad[u]) if(v.fi!=p)
    {
        dfs(v.fi,u);
        if(dd[u]==cnt) dp[u][1]+=min(dp[v.fi][0],dp[v.fi][1]+1);
        else
        {
            F+=min(dp[v.fi][1],dp[v.fi][0]);
            int c=dp[v.fi][0];
            if(v.se>1) c=min(c,dp[v.fi][1]+1);
            dp[u][0]+=c;
            M=min(M,dp[v.fi][1]-c);
        }
    }
    if(dd[u]!=cnt)
    {
        dp[u][1]=dp[u][0]+M;
        dp[u][0]=min(dp[u][0],F+1);
    }
}
void build()
{
    sort(all(Q), cmp);
    forinc(i,1,m) Q.pb(LCA(Q[i],Q[i-1]));
    sort(all(Q));
    Q.erase(unique(all(Q)), Q.end());
    sort(all(Q), cmp);
    m = Q.size()-1;
    forinc(i, 0, m) ad[Q[i]].clear();
    top = 0;
    bool ok=1;
    forinc(i, 0, m) {
        while (top && tout[Q[i]] >= tout[st[top]]) top--;
        if (top)
        {
            int l=d[Q[i]]-d[st[top]];
            if(dd[Q[i]]==cnt&&dd[st[top]]==cnt&&l==1) {ok=0;break;}
            ad[Q[i]].pb({st[top],l});
            ad[st[top]].pb({Q[i],l});
        }
        st[++top] = Q[i];
    }
    if(!ok) {cout<<-1<<"\n";return;}
    dfs(Q[0],0);
    cout<<min(dp[Q[0]][1],dp[Q[0]][0])<<"\n";
}
main()
{
    //freopen("613D.inp","r",stdin);
    n=in;
    lg=log2(n);
    forinc(i,1,n-1)
    {
        int u=in,v=in;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    DFS(1);
    forinc(cs,1,in) {
        Q.clear(); int u;
        m=in;++cnt;
        forinc(i,1,m)
        {
            int u=in;
            dd[u]=cnt;
            Q.pb(u);
        }
        build();
    }
}