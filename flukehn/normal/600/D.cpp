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
using ld=long double;
#define double ld
const double pi=acos(-1);
struct cir{
  int x,y,r;
  auto& read(){
    return cin>>x>>y>>r;
  }
};
cir a,b;
ll sqr(int x){return 1ll*x*x;}
double tr(double w){
  return w/pi*180;
}
double work(){
  if(a.r<b.r)swap(a,b);
  ll d=sqr(a.x-b.x)+sqr(a.y-b.y);
  if(sqr(a.r-b.r)>=d){
    return sqr(b.r)*pi;
  }
  if(d>=sqr(a.r+b.r))return 0.0;
  double l=sqrtl(d),r1=a.r,r2=b.r;
  double w1=acos((r1*r1+d-r2*r2)/2.0/r1/l)*2.0;
  double w2=acos((r2*r2+d-r1*r1)/2.0/r2/l)*2.0;
  dbg(l,r1,r2);
  dbg(tr(w1),tr(w2));
  return (r1*r1*w1+r2*r2*w2-r1*r1*sin(w1)-r2*r2*sin(w2))*0.5;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cout<<fixed<<setprecision(20);
  while(a.read()&&b.read()){
    cout<<work()<<'\n';
  }
}