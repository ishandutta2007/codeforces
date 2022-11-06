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
struct R{
  int x,y,r1,r2;
  void read(){
    cin>>x>>y>>r1>>r2;
  }
};
int sqr(int x){return x*x;}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  R a,b;
  a.read();
  b.read();
  int rr=sqr(a.x-b.x)+sqr(a.y-b.y);
  int ans=0;
  
  auto chk1=[&](){
    dbg(rr, sqr(a.r1+b.r2),sqr(b.r1-a.r1));
    return (a.r1>=b.r2&&sqr(a.r1-b.r2)>=rr) || (rr>=sqr(a.r1+b.r2)) || (b.r1>=a.r1&&rr<=sqr(b.r1-a.r1));
  };
  auto chk2=[&](){
    return (a.r2>=b.r2&&sqr(a.r2-b.r2)>=rr) || (rr>=sqr(a.r2+b.r2)) || (b.r1>=a.r2&&rr<=sqr(b.r1-a.r2));
  };
  ans+=chk1();
  ans+=chk2();
  dbg(ans);
  swap(a,b);
  ans+=chk1();
  ans+=chk2();
  cout<<ans<<'\n';
}