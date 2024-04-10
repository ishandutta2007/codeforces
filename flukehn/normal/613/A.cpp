#include<bits/stdc++.h>
using namespace std;
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
  inline P operator+(const P&t)const{return P(x+t.x,y+t.y);}
  inline P operator-(const P&t)const{return P(x-t.x,y-t.y);}
  P operator*(T s)const{return P(x*s,y*s);}
  P& operator+=(const P&t){return *this=P(x+t.x,y+t.y);}
  P& operator-=(const P&t){return *this=P(x-t.x,y-t.y);}
  P& operator*=(T s){return *this=P(x*s,y*s);}

  inline T operator*(const P&t)const{
    return x*t.x+y*t.y;
  }
  inline T cha(const P&t)const{
    return x*t.y-y*t.x;
  }
  inline T dis(const P&t)const{
    return (x-t.x)*(x-t.x)+(y-t.y)*(y-t.y);
  }
  inline ld dist(const P&t)const{
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

int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cout<<fixed<<setprecision(10);
  using E=P<double>;
  const double pi=acos(-1),inf=1e18;
  int n;
  while(cin>>n){
    E o;
    vector<E> p(n);
    cin>>o.x>>o.y;
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    double R=0,r=inf;
    for(int i=0;i<n;++i){
      double d=o.dist(p[i]);
      R=max(R,d);
      r=min(r,d);
      int j=(i+1)%n;
      double a=o.dis(p[i]);
      double b=o.dis(p[j]);
      double c=p[i].dis(p[j]);
      if(a*a<b*b+c*c&&b*b<a*a+c*c){
        double w=(o-p[i]).cha(p[j]-p[i])/sqrt(c);
        r=min(r,abs(w));
      }
    }
    double ans=(R*R-r*r)*pi;
    cout<<ans<<"\n";
  } 
}