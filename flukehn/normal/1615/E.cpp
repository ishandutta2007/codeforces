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
const int N=2e5+11;
int n,K;
vector<int> e[N];
int fa[N],dep[N],sz[N];
int sc[N],tp[N];
int lca(int x,int y){
  for(;tp[x]!=tp[y];){
    if(dep[tp[x]]<dep[tp[y]])swap(x,y);
    x=fa[tp[x]];
    //dbg(x,y);
  }
  if(dep[x]<dep[y])swap(x,y);
  return y;
}
int lf[N],m;
void dfs(int x){
  //dfn[++cnt]=x;
  sz[x]=1;
  sc[x]=0;
  for(int y:e[x]){
    e[y].erase(find(ALL(e[y]),x));
    fa[y]=x;
    dep[y]=dep[x]+1;
    dfs(y);
    sz[x]+=sz[y];
    if(sz[y]>sz[sc[x]])
      sc[x]=y;
  }
  if(!sc[x]) {
    lf[++m]=x;
  }
 // if(sc[x]) e[x].erase(find(ALL(e[x]),sc[x]));
}
multiset<int> dfs2(int x,int t){
  tp[x]=t;
  if(!sc[x]){
    return multiset<int>{1};
  }else{
    auto r=dfs2(sc[x],t);
    for(int y:e[x])if(y!=sc[x]){
      auto g=dfs2(y,y);
      for(int x:g)r.insert(x);
    }
    auto p=r.end();
    --p;
    int x=*p;
    r.erase(p);
    r.insert(x+1);
    return r;
  }
}

ll solve(){
  lf[0]=1;
  m=0;
  for(int i=1;i<=n;++i)e[i].clear();
  for(int i=1;i<n;++i){
    int x,y;
    cin>>x>>y;
    e[x].pb(y);
    e[y].pb(x);
  }
  dfs(1);
  auto s=dfs2(1,1);
  ll ans=-1145141919810LL;
  int p=n;
  auto calc=[](int n,int m){
    m=min(m,n/2);
    return 1ll*n*m-1ll*m*m;
  };
  for(int i=1;i<=K;++i){
    if(!s.empty()){
      p-=*s.rbegin();
      s.erase(s.lower_bound(*s.rbegin()));
    }
    dbg(i,p);
    upmx(ans,1ll*n*i-1ll*i*i-calc(n,p));
  }
  return ans;
  //if(m<=K) return 1ll*n*(n/2)-1ll*(n/2)*(n/2);
  
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n>>K)cout<<solve()<<"\n";
}