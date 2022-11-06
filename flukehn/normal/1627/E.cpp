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
inline int reduce(int x){return x+(x>>31&mo);}
inline int& inc(int &x,int y){return x=reduce(x+y-mo);}
inline int& dec(int &x,int y){return x=reduce(x-y);}
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
/*
template<class T>
struct P{
  int n,m;
  vector<T> a;
  T* operator[](int x){
    return &a[x*m];
  }
  void init(int _n,int _m,const T w){
    n=_n,m=_m;
    a.clear();
    For(i,0,n*m) a.pb(w);
  }
};
*/
int n,m,K;
const int N=1e5+11;
ll val[N];
using E=tuple<int,int,int>;
//P<ll> f;
//P<vector<E> > g;
//P<int> vis;
const ll inf=~0uLL>>3;
/*struct B{
  int x,y;
  ll w;
  bool operator<(const B&t)const{
    if(x!=t.x) return x>t.x;
    return w>t.w;
  }
};*/
//priority_queue<B> q;
using vi=vector<pair<int,ll>>;
vi f[N];
vi g[N];
map<pa,vector<E> > Z;

void wk(int i,int l,int r,int L,int R){
  if(l>=r||L>=R) return;
  int m=(l+r)>>1;
  int p=-1;
  ll now=inf/2;
  For(j,L,R)
    if(upmn(now,1LL*val[i]*abs(g[i][j].fi-f[i][m].fi)+g[i][j].se))
      p=j;
  //dbg(i,m,val[i],g[i][p].se,g[i][p].fi,f[i][m].fi,now);
  if(p<0) return;
  f[i][m].se=now;
  wk(i,l,m,L,p+1);
  wk(i,m+1,r,p,R);
}
void solve(){
  dbg(inf/1e18);
  cin>>n>>m>>K;
  for(int i=0;i<n;++i)cin>>val[i];
  for(int i=0;i<=n;++i){
    f[i].clear();
    g[i].clear();
  }
  Z.clear();
  //f.init(n,m,inf);
  //g.init(n,m,vector<E>{});
  //vis.init(n,m,0);
  g[0].pb(0,0LL);
  For(i,0,K){
    int a,c,b,d,h;
    cin>>a>>b>>c>>d>>h;
    dbg(a,b,c,d,h);
    f[a-1].pb(b-1,inf);
    g[c-1].pb(d-1,inf);
    Z[pa(a-1,b-1)].pb(c-1,d-1,h);
    //g[a-1][b-1].pb(c-1,d-1,h);
  }
  f[n-1].pb(m-1,inf);
  For(i,0,n){
    sort(ALL(f[i]));
    f[i].resize(unique(ALL(f[i]))-f[i].begin());
  }
  For(i,0,n){
    sort(ALL(g[i]));
    g[i].resize(unique(ALL(g[i]))-g[i].begin());
  }
  For(i,0,n){
    wk(i,0,SZ(f[i]),0,SZ(g[i]));
    for(auto [y,w]:f[i]){
      for(auto [c,d,h]: Z[pa(i,y)]){
        
        auto t=lower_bound(ALL(g[c]),make_pair(d,-inf));
        dbg(c,t->fi,d,h,i,y,w);
        assert(t->fi==d);
        upmn(t->se,w-h);
      }
    }
  }
  //f[0][0]=0;
  //q.push((B){0,0,0LL});
  /*while(!q.empty()){
    auto [x,y,w]=q.top();
    dbg(x,y);
    q.pop();
    if(vis[x][y]) continue;
    vis[x][y]=1;
    auto G=[&](int u,int v,ll d){
      if(upmn(f[u][v],d)){
        q.push((B){u,v,d});
      }
    };
    if(y>=1) G(x,y-1,w+val[x]);
    if(y<m-1) G(x,y+1,w+val[x]);
    for(auto [c,d,l]:g[x][y])
      G(c,d,w-l);
  }*/
  assert(f[n-1].back().fi==m-1);
  ll ans=f[n-1].back().se;
  if(ans>inf/2) {
    cout<<"NO ESCAPE\n";
  }else{
    cout<<ans<<"\n";
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
}