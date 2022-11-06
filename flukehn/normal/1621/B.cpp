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
const int N=1e5;
const int inf=~0u>>2;
int n;

void solve(){
  ll l=1e18,r=-1e18;
  ll lm=0,rm=0,tm=0;
  cin>>n;
  For(i,0,n){
    ll x,y,c;
    cin>>x>>y>>c;
    int t1=upmn(l,x);
    int t2=upmx(r,y);
    if(t1) lm=c;
    else if(l==x) upmn(lm,c);
    if(t2) rm=c;
    else if(r==y) upmn(rm,c);
    if(t1||t2){
      if(l==x&&r==y)tm=c;
      else tm=1e18;
    } else if(l==x&&r==y) upmn(tm,c);
    ll ans=lm+rm;
    //dbg(t1,t2,l,r,lm,rm,tm);
    upmn(ans,tm);
    cout<<ans<<"\n";
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