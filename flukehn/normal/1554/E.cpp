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
const int N=1e5+11;
int n;
vector<int> e[N];
int a[N];
int fl,S;
int ans[N];
int dfs(int x,int fa){
  int r=e[x].size();
  for(int y:e[x]){
    if(y==fa){
      continue;
    }
    r-=dfs(y,x);
    if(!fl) return 1;
  }
  const int w=r%S;
  if((w==1 && x==1) || w>1) fl=0;
  if(fl) {
    a[x]=r-w;
  }
  return w^1;
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;++i)e[i].clear();
  for(int i=1;i<=n;++i)ans[i]=0;
  For(i,1,n){
    int u,v;
    cin>>u>>v;
    e[u].pb(v);
    e[v].pb(u);
  }
  ans[1]=1;
  For(i,1,n)inc(ans[1],ans[1]);
  vector<int> p;
  int x=n-1;
  for(int i=2;i*i<=x;++i)
    if(x%i==0) {
      p.pb(i);
      while(x%i==0)x/=i;
    }
  if(x>1)p.pb(x);
  for(int x:p){
    S=x;
    fl=1;
    dfs(1,0);
    if(fl){
      int t=0;
      for(int i=1;i<=n;++i)t=__gcd(t,a[i]);
      ans[t]=1;
    }
  }
  for(int i=2;i<=n;++i)dec(ans[1],ans[i]);
  for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  //For(i,0,100) assert(__gcd(0,0) ==0);
  //dbg(__gcd(0,0));
  int t;
  cin>>t;
  while(t--)solve();
}