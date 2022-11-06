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
const int N=50011;
int a[N],x;
int n;
int f[N][3];
int solve(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i];
  cin>>x;
  for(int i=1;i<=n;++i)a[i]-=x;
  f[0][0]=0;
  for(int i=1;i<=n;++i){
    memset(f[i],0x3f,sizeof f[i]);
    if(i==1) {
      f[i][0]=1;
      f[i][1]=0;
    }else if(i==2){
      f[i][0]=1;
      f[i][1]=1;
      if(a[1]+a[2]>=0) f[i][2]=0;
    }else{
      f[i][0]=1+min({f[i-1][0],f[i-1][1],f[i-1][2]}); 
      f[i][1]=f[i-1][0];
      if(a[i]+a[i-1]>=0){
        f[i][2]=f[i-1][1];
        if(a[i]+a[i-1]+a[i-2]>=0)
          upmn(f[i][2],f[i-1][2]);
      }
    }
  }
  return n-min({f[n][0],f[n][1],f[n][2]});
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)cout<<solve()<<"\n";
}