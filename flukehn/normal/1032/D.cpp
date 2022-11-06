#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb push_back
#define epb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class A,class B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<class A,class B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
template<class A,class B>inline A gcd(A x,B y){for(;y;swap(x,y))x%=y;return x;}
using ll=long long;
using pa=pair<int,int>;
const int mo=998244353;
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
inline void inc(int &x,int y){x=x+y>=mo?x+y-mo:x+y;}
inline void dec(int &x,int y){x=x-y<0?x-y+mo:x-y;}
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) cerr<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl;
#else
#define debug(...)
#define dbg(x)
#endif

#define y1 y11111
double a,b,c;
ll x1,y1,x2,y2;
const double eps=1e-9;
double work(){
  cin>>x1>>y1>>x2>>y2;
  double ans=abs(x1-x2)+abs(y1-y2);
  //ax+by+c=0
  //y=-(c+a*x)/b x=-(c+b*y)/a;
  if(abs(a)<eps||abs(b)<eps)return ans;
  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      double u,v,x,y;
      if(!i){
        u=x1;
        v=-(c+a*x1)/b;
      }else{
        u=-(c+b*y1)/a;
        v=y1;
      }
      if(!j){
        x=x2;
        y=-(c+a*x2)/b;
      }else{
        x=-(c+b*y2)/a;
        y=y2;
      }
      upmn(ans,abs(u-x1)+abs(v-y1)+abs(x-x2)+abs(y-y2)+sqrt((u-x)*(u-x)+(v-y)*(v-y)));
    }
  }
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cout<<fixed<<setprecision(10);
  while(cin>>a>>b>>c)
    cout<<work()<<"\n";
}