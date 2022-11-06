#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb push_back
#define epb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using ll=long long;
using pa=pair<int,int>;
template<class A,class B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<class A,class B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
template<class A,class B>inline A gcd(A x,B y){for(;y;swap(x,y))x%=y;return x;}
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
int r,h;
int work(){
  int ans=h/r*2;
  h%=r;
  //h + r\ge \frac{\sqrt 3}{2}r+r
  if(4ll*h*h>=3ll*r*r)ans+=3;
  else if(2*h>=r)ans+=2;
  else ans+=1;
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>r>>h)
    cout<<work()<<"\n";
}