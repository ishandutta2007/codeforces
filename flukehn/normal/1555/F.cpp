#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb emplace_back
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
using ll=long long;
using pa=pair<int,int>;
template<class A,class B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<class A,class B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
const int mo=998244353;
constexpr int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
constexpr int reduce(int x){return x+(x>>31&mo);}
constexpr int& inc(int &x,int y){return x=reduce(x+y-mo);}
constexpr int& dec(int &x,int y){return x=reduce(x-y);}
#ifdef flukehn
void debug_out(){cerr<<endl;}
template <typename Head,typename... Tail>
void debug_out(Head H,Tail... T){
  cerr<<" "<<H;//to_string(H);
  debug_out(T...);
}
#define dbg(...) cerr<<"L"<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
#define debug(...) cerr<<__VA_ARGS__//fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=3e5+11,MX=5e5+11;
int n,m;
int f[N];
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
int eu[MX],ev[MX],ew[MX];
int ans[MX];
vector<pa> e[N];
int p[N],d[N],sz[N],sc[N];
int g[N];
int tp[N];
int dfn[N],idfn[N],cnt;
void dfs(int x){
  sz[x]=1;
  for(auto [y,w]:e[x]){
    p[y]=x;
    d[y]=d[x]+1;
    g[y]=g[x]^w;
    e[y].erase(find(e[y].begin(),e[y].end(),pa(x,w)));
    dfs(y);
    sz[x]+=sz[y];
    if(sz[y]>sz[sc[x]])sc[x]=y;
  }
}
void dfs_2(int x,int t){
  dfn[x]=++cnt;
  idfn[cnt]=x;
  tp[x]=t; 
  if(sc[x]){
    dfs_2(sc[x],t);
    for(auto [y,w]:e[x]){
      if(y!=sc[x]){
        dfs_2(y,y);
      }
    }
  }
}
namespace sgt{
  const int M=N<<2;
  int cov[M],hav[M];
#define m ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
  void build(int x,int l,int r){
    return;
  }
  int ql,qr;
  void upd(int x,int l,int r){
    if(cov[x]) return;
    hav[x]=1;
    if(ql<=l&&r<=qr){
      cov[x]=1;
      return;
    }else{
      if(ql<m) upd(ls,l,m);
      if(qr>m) upd(rs,m,r);
      cov[x]|=cov[ls]&&cov[rs];
    }
  }
  int qry(int x,int l,int r){
    if(cov[x]) return 1;
    if(ql<=l&&r<=qr){
      return hav[x];
    }else{
      return (ql<m?qry(ls,l,m):0) || (qr>m?qry(rs,m,r):0);
    }
  }
  void upd(int l,int r){
    ql=l,qr=r;
    upd(1,1,n+1);
  }
  int qry(int l,int r){
    ql=l,qr=r;
    return qry(1,1,n+1);
  }
#undef m
#undef ls
#undef rs
}
using sgt::upd;
using sgt::qry;
int chk(int x,int y){
  for(;tp[x]!=tp[y];){
    if(d[tp[x]]<d[tp[y]]) swap(x,y);
    if(qry(dfn[tp[x]],dfn[x]+1)) return 0;
    x=p[tp[x]];
  }
  if(d[x]<d[y])swap(x,y);
  if(x!=y){
    if(qry(dfn[y]+1,dfn[x]+1)) return 0;
  }
  return 1;
}
void cov(int x,int y){
  for(;tp[x]!=tp[y];){
    if(d[tp[x]]<d[tp[y]]) swap(x,y);
    upd(dfn[tp[x]],dfn[x]+1);
    x=p[tp[x]];
  }
  if(d[x]<d[y])swap(x,y);
  if(x!=y){
    upd(dfn[y]+1,dfn[x]+1);
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;++i)f[i]=i;
  For(i,0,m){
    cin>>eu[i]>>ev[i]>>ew[i];
    //assert(eu[i]<=n&&ev[i]<=n);
    int x=fa(eu[i]);
    int y=fa(ev[i]);
    if(x!=y){
      ans[i]=1;
      f[x]=y;
      e[eu[i]].pb(ev[i],ew[i]);
      e[ev[i]].pb(eu[i],ew[i]);
    }
  }
  for(int i=1;i<=n;++i)
    if(!sz[i]) dfs(i);
  for(int i=1;i<=n;++i)
    if(!p[i]) dfs_2(i,i);
  //sgt::build(1,1,n+1);
  For(i,0,m){
    if(ans[i])continue;
    int x=eu[i],y=ev[i],w=ew[i];
    if((g[x]^g[y]) == w) continue;
    if(!chk(x,y)) continue;
    ans[i]=1;
    cov(x,y);
  }
  For(i,0,m)cout<<(ans[i]?"YES":"NO")<<"\n";
}