#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
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
const int N=100010;
int n,m,mem[4*N],d[N],a[N],f[N][20],tin[N],tout[N],id,lg,t[N],v[N],ans,res;
pii ti[4*N],to[4*N];
vector<pii> ke[N];
void dfs(int u,int p)
{
    tin[u]=++id;
    v[id]=u;
    forinc(i,1,lg) f[u][i]=f[f[u][i-1]][i-1];
    forv(v,ke[u]) if(v.fi!=p)
    {
        f[v.fi][0]=u;
        d[v.fi]=d[u]+v.se;
        dfs(v.fi,u);
    }
    tout[u]=id;
}
bool cheq(int u,int v)
{
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int LCA(int u,int v)
{
    if(cheq(u,v)) return u;
    if(cheq(v,u)) return v;
    fordec(i,lg,0) if(!cheq(f[u][i],v)&&f[u][i]!=0) u=f[u][i];
    return f[u][0];
}
pii maxi(pii x,pii y)
{
    if(x.fi!=y.fi) return (x.fi>y.fi)?x:y;
    return (tin[x.se]>tin[y.se])?x:y;
}
pii maxo(pii x,pii y)
{
    if(x.fi!=y.fi) return (x.fi>y.fi)?x:y;
    return (tout[x.se]<tout[y.se])?x:y;
}
void build(int s,int l,int r)
{
    if(l==r)
    {
        ti[s].se=to[s].se=v[l];
        ti[s].fi=to[s].fi=(!a[v[l]])?-1e9:d[v[l]];
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    ti[s]=maxi(ti[2*s],ti[2*s+1]);
    to[s]=maxo(to[2*s],to[2*s+1]);
    //cout<<ti[2*s].se<<" "<<ti[2*s+1].se<<" "<<ti[s].se<<"\n";
}
void tran(int s)
{
    if(!mem[s]) return;
    int x=mem[s];
    mem[s]=0;
    ti[2*s].fi+=x;ti[2*s+1].fi+=x;
    to[2*s].fi+=x;to[2*s+1].fi+=x;
    mem[2*s]+=x;mem[2*s+1]+=x;
}
void update(int s,int l,int r,int u,int v,int x)
{
    if(l>v||r<u) return;
    if(l>=u&&r<=v)
    {
        ti[s].fi+=x;
        to[s].fi+=x;
        mem[s]+=x;
        return;
    }
    int mid=(l+r)/2;
    tran(s);
    update(2*s,l,mid,u,v,x);
    update(2*s+1,mid+1,r,u,v,x);
    ti[s]=maxi(ti[2*s],ti[2*s+1]);
    to[s]=maxo(to[2*s],to[2*s+1]);
}
int get(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return -1e9;
    if(l>=u&&r<=v) return ti[s].fi;
    int mid=(l+r)/2;
    tran(s);
    return max(get(2*s,l,mid,u,v),get(2*s+1,mid+1,r,u,v));
}
void DFS(int u,int p)
{
    forv(v,ke[u]) if(v.fi!=p)
    {
        update(1,1,n,1,n,v.se);
        update(1,1,n,tin[v.fi],tout[v.fi],-2*v.se);
        if(a[v.fi])
        {
            pii x=ti[1],y=to[1];
            if(x.fi>=0)
            {
                int z=LCA(x.se,y.se);
                //cout<<v.fi<<" "<<z<<"\n";
                if(cheq(v.fi,z)) t[z]++,t[u]--;
                else if(cheq(z,v.fi))
                {
                    if(get(1,1,n,tin[v.fi],tout[v.fi])<x.fi)
                    {
                        t[v.fi]++;
                        int p=v.fi;
                        fordec(i,lg,0)
                        {
                            int j=f[p][i];
                            if(j&&get(1,1,n,tin[j],tout[j])<x.fi) p=j;
                        }
                        t[f[p][1]]--;
                    }
                }
                else
                {
                    int p=LCA(v.fi,z);
                    t[v.fi]++;t[z]++;
                    t[p]--;t[f[p][0]]--;
                }
            }
        }
        DFS(v.fi,u);
        update(1,1,n,1,n,-v.se);
        update(1,1,n,tin[v.fi],tout[v.fi],2*v.se);
    }
}
void Dfs(int u,int p)
{
    forv(v,ke[u]) if(v.fi!=p)
    {
        Dfs(v.fi,u);
        t[u]+=t[v.fi];
    }
    //cout<<u<<" "<<t[u]<<"\n";
    if(a[u]) return;
    if(t[u]>ans) ans=t[u],res=0;
    if(t[u]==ans) ++res;
}
main()
{
    //freopen("348E.inp","r",stdin);
    //freopen("348E.out","w",stdout);
    n=in,m=in;
    lg=log2(n);
    while(m--) a[in]=1;
    forinc(i,1,n-1)
    {
        int u=in,v=in,c=in;
        ke[u].pb({v,c});
        ke[v].pb({u,c});
    }
    dfs(1,0);
    build(1,1,n);
    if(a[1])
    {
        pii x=ti[1],y=to[1];
        if(x.fi>=0)
        {
            int z=LCA(x.se,y.se);
            t[z]++;
        }
    }
    DFS(1,0);
    //forinc(i,1,n) cout<<t[i]<<" ";cout<<"\n";
    Dfs(1,0);
    cout<<ans<<" "<<res<<"\n";
}