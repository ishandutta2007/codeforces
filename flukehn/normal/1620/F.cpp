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
const int N=1e6+11;
const int inf=~0u>>1;
int n;
int p[N];
int f[N][2][2];
int g[N][2][2];
int ans[N];
void solve(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>p[i];
  if(n==1){
    cout<<"YES\n1\n";
    return;
  }
// (x,y) (+-)
  for(int i=0;i<=n+1;++i)For(u,0,2)For(v,0,2)f[i][u][v]=inf;
  f[1][0][0]=-inf;
  f[1][0][1]=-inf;
  for(int i=1;i<n;++i){
    //dbg(i);
    For(u,0,2)For(v,0,2){
      int x=v==0?p[i]:-p[i];
      int y=f[i][u][v];
      if(u)swap(x,y);
      //dbg(i,x,y);
      if(p[i+1]>x){
        if(upmn(f[i+1][0][0],y)) g[i+1][0][0]=u*2+v;
      }else if(p[i+1]>y){
        if(upmn(f[i+1][1][0],x)) g[i+1][1][0]=u*2+v;
      }
      if(-p[i+1]>x){
        if(upmn(f[i+1][0][1],y)) g[i+1][0][1]=u*2+v;
      }else if(-p[i+1]>y){
        if(upmn(f[i+1][1][1],x)) g[i+1][1][1]=u*2+v;
      }
    }
  }
  int w;
  for(w=0;w<4;++w)
    if(f[n][w/2][w%2]<=n+1)break;
  if(w==4){
    cout<<"NO\n";
  }else{
    cout<<"YES\n";
    for(int i=n;i>=1;w=g[i][w/2][w&1],--i){
      ans[i]=w%2?-p[i]:p[i]; 
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)solve();
}