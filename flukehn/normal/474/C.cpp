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
#define debug(...) cerr<<__VA_ARGS__//fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
#define EPS (1e-9)
using ld=double;
inline int sgn(ld x){
  return abs(x)<EPS?0:(x<0?-1:1);
}
inline int sgn(long long x){
  return !x?0:(x<0?-1:1);
}
template<class T>
struct P{
  T x,y;
  P(T x=0,T y=0):x(x),y(y){}
  P operator+(const P&t)const{return P(x+t.x,y+t.y);}
  P operator-(const P&t)const{return P(x-t.x,y-t.y);}
  P operator*(T s)const{return P(x*s,y*s);}
  P& operator+=(const P&t){return *this=P(x+t.x,y+t.y);}
  P& operator-=(const P&t){return *this=P(x-t.x,y-t.y);}
  P& operator*=(T s){return *this=P(x*s,y*s);}
  bool operator!=(const P&t)const{
    return sgn(x-t.x)||sgn(y-t.y);
  }
  T operator*(const P&t)const{
    return x*t.x+y*t.y;
  }
  T cha(const P&t)const{
    return x*t.y-y*t.x;
  }
  T dis(const P&t)const{
    return (x-t.x)*(x-t.x)+(y-t.y)*(y-t.y);
  }
  ld dist(const P&t)const{
    return sqrt(this->dis(t));
  }
};
template<class T>
vector<P<T>> convex_hull(vector<P<T>> a){
  int n=a.size();
  for(int i=1;i<n;++i){
    int w=sgn(a[i].y-a[0].y);
    if(w<0||(!w&&sgn(a[i].x-a[0].x)<0)){
      swap(a[0],a[i]);	
    }
  }
  auto p=a[0];
  for(auto &e:a)e-=p;
  sort(a.begin()+1,a.end(),[](P<T> a,P<T> b){
    int w=sgn(a.cha(b));
    return w?(w>0):a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
  });
  vector<P<T>> b(n);
  int m=0;
  for(auto e:a){
    while(m>1&&sgn((b[m-1]-b[m-2]).cha(e-b[m-2]))<=0)--m;
    b[m++]=e;
  }
  b.resize(m);
  for(auto &e:b)e+=p;
  return b;
}
const int inf=~0u>>2;
const int N=4;
int x[N],y[N],a[N],b[N];
int u[N],v[N];
void turn(int &x,int &y,int a,int b){
  x-=a;
  y-=b;
  swap(x,y);
  x=-x;
  x+=a;
  y+=b;
}
ll sqr(ll x){return x*x;}
int chk(){
  For(j,0,4)
    For(k,j+1,4)
      if(u[j]==u[k]&&v[j]==v[k])
        return 0;
  using E=P<ll>;
  vector<E> p(4);
  For(i,0,4)p[i]=E(u[i],v[i]);
  p=convex_hull(p);
  if(SZ(p)!=4)return 0;
  if(p[1]-p[0]!=p[2]-p[3])return 0;
  if(sqr((p[2]-p[0]).cha(p[3]-p[1]))!=p[2].dis(p[0])*p[1].dis(p[3]))
    return 0;
  For(i,0,4){
    int j=(i-1+4)%4;
    int k=(i+1)%4;
    auto u=p[j]-p[i];
    auto v=p[k]-p[i];
    //dbg(u.cha(v));
    if(sqr(u.cha(v))!=u.dis(E(0,0))*v.dis(E(0,0)))
      return 0;
  }
  return 1;
}
int work(){
  int ans=inf; 
  For(i,0,N)cin>>x[i]>>y[i]>>a[i]>>b[i];
  For(i,0,1<<2*N){
    int tot=0;
    For(j,0,N){
      u[j]=x[j];
      v[j]=y[j];
      int w=(i>>2*j+1&1)*2+(i>>2*j&1);
      //dbg(i,j,w);
      tot+=w;
      For(k,0,w)
        turn(u[j],v[j],a[j],b[j]);
    }
    if(chk()){
      upmn(ans,tot);
      dbg(tot,i);
    }
  }
  return ans==inf?-1:ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)
    cout<<work()<<'\n';
}