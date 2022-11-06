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
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) cerr<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl;
#else
#define debug(...)
#define dbg(x)
#endif
struct P{
  int x,y;
  P()=default;
  P(int u,int v){
    if(v<0)v=-v,u=-u;
    if(v==0)u=1;
    else{
      int g=gcd(abs(u),v);
      u/=g;
      v/=g;
    }
    x=u,y=v;
  }
  bool operator<(const P&t)const{
    return 1ll*x*t.y<1ll*y*t.x;
  }
  bool operator==(const P&t)const{
    return 1ll*x*t.y==1ll*y*t.x;
  }
};
    
const int N=1e5+11;
int n;
int work(){
  vector<P> a;
  for(int i=0;i<n;++i){
    int k,b;
    cin>>k>>b;
    if(k==0)continue;
    a.pb(P(-b,k));
  }
  sort(a.begin(),a.end());
  int ret=0;
  int m=SZ(a);
  for(int i=0,j;i<m;i=j){
    for(j=i;j<m&&a[j]==a[i];++j){
    }
    ++ret;
  }
  return ret;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n){
    cout<<work()<<"\n";
  }
}