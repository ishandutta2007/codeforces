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
const int N=5011;
int c[N][N];
char s[N];
int n,k;
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  For(i,0,N){
    c[i][0]=1;
    For(j,1,i+1)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
  }
  cin>>n>>k;
  cin>>s;
  vector<int> a;
  a.pb(0);
  For(i,0,n) if(s[i]=='1') a.pb(i+1);
  a.pb(n+1);
  int m=SZ(a)-2;
  dbg(m);
  int ans=1;
  for(int i=k;i<=m;++i){
    dbg(a[i+1]-a[i-k]-1);
    inc(ans,c[a[i+1]-a[i-k]-1][k]-1);
    dbg(i);
  }
  if(k){
    for(int i=k+1;i<=m;++i){
      dec(ans,c[a[i]-a[i-k]-1][k-1]-1);
    }
  }
  cout<<ans<<"\n";
}