#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e5+11;
int y[N];
int yy[N],len[N];
int a,b;
double ans;
int S,T;
int n,m;
ll sqr(int x){return 1ll*x*x;}
void solve(int l,int r,int L,int R){
  if(l>=r||L>=R){
    return;
  }
  int m=(l+r)>>1;
  int p=-1;
  double tmp=1e18;
  double d=sqrt(sqr(a)+sqr(y[m]));
  For(i,L,R){
    double th=sqrt(sqr(a-b)+sqr(y[m]-yy[i]))+d+len[i];
    if(upmn(tmp,th))p=i;
    if(upmn(ans,th)){
      S=m;
      T=i;
    }
  }
  solve(l,m,L,p+1);
  solve(m+1,r,p,R);
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>m>>a>>b;
  For(i,0,n)cin>>y[i];
  For(i,0,m)cin>>yy[i];
  For(i,0,m)cin>>len[i];
  ans=1e18;
  solve(0,n,0,m);
  cout<<S+1<<" "<<T+1<<"\n";
  //cout<<fixed<<setprecision(10)<<ans<<"\n";
}