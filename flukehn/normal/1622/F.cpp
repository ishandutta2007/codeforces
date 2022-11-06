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
mt19937_64 rnd;
const int N=1e6+11;
using ull=unsigned long long;
int np[N],p[N],tot;
ull h[N],f[N];
void init(){
  h[1]=0;
  for(int i=2;i<N;++i){
    if(!np[i]){
      p[tot++]=i;
      h[i]=rnd();
    }
    for(int j=0,k;j<tot&&(k=i*p[j])<N;++j){
      np[k]=1;
      h[k]=h[i]^h[p[j]];
      if(i%p[j]==0)break;
    }
  }
  for(int i=1;i<N;++i) f[i]=f[i-1]^h[i];
}
int n;
void solve(){
  vector<int> a;
  if(n%2) a.pb(n);
  int k=n/2;
  //dbg(k,f[k]);
  if(f[k]) a.pb(k);
  if(k%2) a.pb(2);
  dbg(SZ(a));
  //debug("a: ");For(i,0,SZ(a)) debug(a[i]<<" \n"[i+1==i_end]);
  auto U=[&](vector<int> b){
    if(SZ(b)<SZ(a)) a.swap(b);
  };
  ull w=0;
  for(int i=1;i<=n;++i) w^=f[i];
  if(w==0) U({});
  else{
    int i;
    for(i=1;i<=n;++i) 
      if(f[i] == w) {
       U({i});
       break;
      }
    if(i>n){
      map<ull,int> g;
      for(i=1;i<=n;++i) g[w^f[i]]=i;
      for(i=1;i<=n;++i) 
        if(g.count(f[i])) {
          U({i,g[f[i]]});
          break;
        }
    }
  }
  sort(ALL(a));
  int p=0;
  vector<int> ans;
  ull c=0;
  for(int i=1;i<=n;++i){
    while(p<SZ(a)&&a[p]<i)++p;
    if(p==SZ(a)||a[p]!=i){
      ans.pb(i);
      c^=f[i];
    }
  }
  assert(!c);
  cout<<SZ(ans)<<"\n";
  For(i,0,SZ(ans))cout<<ans[i]<<" \n"[i+1==i_end];
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  rnd.seed(time(0));
  ios::sync_with_stdio(0),cin.tie(0);
  init();
  while(cin>>n)solve();
}