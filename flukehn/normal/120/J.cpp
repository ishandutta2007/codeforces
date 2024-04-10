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
struct P{
  ll x,y;
  int r,id;
  void read(){
    r=0;
    cin>>x>>y;
    if(x<0)x=-x,r^=1;
    if(y<0)y=-y,r^=2;
  }
};
inline ll sqr(int x){return 1ll*x*x;}
ll dist(P u,P v){
  return (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);
}
const int N=1e5+11;
P a[N];
int n;
P S,T;
ll ans;
void solve(int l,int r){
  if(l+1>=r)return;
  int m=(l+r)/2;
  solve(l,m);
  solve(m,r);
  vector<P> b;
  for(int i=m-1;i>=l&&sqr(a[i].x-a[m].x)<ans;--i)
    b.pb(a[i]);
  for(int i=m;i<r&&sqr(a[i].x-a[m-1].x)<ans;++i)
    b.pb(a[i]);
  sort(all(b),[](P u,P v){
      return u.y<v.y;
      });
  int n=SZ(b);
  int j=0;
  for(int i=0;i<n;++i){
    while(j<i&&sqr(b[i].y-b[j].y)>=ans)++j;
    assert(i-j<10);
    For(k,j,i)
      if(upmn(ans,dist(b[k],b[i]))){
        S=b[k];
        T=b[i];
      }
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#else
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n){
    For(i,0,n)a[i].read(),a[i].id=i+1;
    sort(a,a+n,[](P u,P v){
        return u.x<v.x;
        });
    ans=1e18;
    solve(0,n);
    int i=S.id,j=T.id,u=S.r,v=T.r^3;
    cout<<i<<" "<<u+1<<" "<<j<<" "<<v+1<<"\n";
  }
}