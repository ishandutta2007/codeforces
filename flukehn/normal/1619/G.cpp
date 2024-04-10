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
int f[N],g[N];
int fa(int i){return f[i]==i?i:f[i]=fa(f[i]);}
int x[N],y[N];
int p[N];
int solve(){
  cin>>n>>K;
  for(int i=1;i<=n;++i)f[i]=i;
  for(int i=1;i<=n;++i){
    cin>>x[i]>>y[i]>>g[i];
  }
  for(int i=1;i<=n;++i)p[i]=i;
  auto merge=[](int x,int y){
    x=fa(x);
    y=fa(y);
    if(x!=y){
      f[y]=x;
      g[x]=min(g[x],g[y]);
    }
  };
  sort(p+1,p+n+1,[](int i,int j){
      if(x[i]!=x[j]) return x[i]<x[j];
      return y[i]<y[j];
      });
  for(int i=2;i<=n;++i)
    if(x[p[i]]==x[p[i-1]]&&y[p[i-1]]+K>=y[p[i]])
      merge(p[i],p[i-1]);
  sort(p+1,p+n+1,[](int i,int j){
      if(y[i]!=y[j]) return y[i]<y[j];
      return x[i]<x[j];
      });
  for(int i=2;i<=n;++i)
    if(y[p[i]]==y[p[i-1]]&&x[p[i-1]]+K>=x[p[i]])
      merge(p[i],p[i-1]);
  vector<int> t;
  for(int i=1;i<=n;++i)if(fa(i)==i) t.pb(g[i]);
  sort(ALL(t));
  int m=SZ(t);
  int p=0;
  int i;
  for(i=0;i<m-1;++i){
    while(p<m&&t[p]<=i)++p;
    if(m-p <= i+1) break;
  }
  return i;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--) cout<<solve()<<"\n";
}