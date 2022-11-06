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
const int N=2e5+11;
const ll inf=~0uLL>>4;
int n,m;
int a[N];
pa b[N],c[N];
ll f[N],g[N];
ll solve(){
  cin>>n>>m;
  For(i,0,n)cin>>a[i];
  For(i,0,m)cin>>b[i].fi>>b[i].se;
  sort(a,a+n);
  sort(b,b+m);
  int t=0,p=0,q=0;
  For(i,0,m){
    while(p<n&&a[p]<b[i].fi)++p;
    if(p<n&&a[p]<=b[i].se)continue;
    if(t&&c[t].fi==b[i].fi)continue;
    while(t&&c[t].se>=b[i].se)--t;
    c[++t]=b[i];
  }
  m=t;
  if(!m) return 0;
  p=0;
  for(p=1;p<=m;++p)
    if(c[p].fi>a[0])break;
  if(n==1){
    if(p==1) return c[m].fi-a[0];
    if(p==m+1) return a[0]-c[1].se;
    return (ll)c[m].fi-c[1].se+min(a[0]-c[1].se,c[m].fi-a[0]);
  }
  for(int i=0;i<=m+1;++i)f[i]=~0uLL>>4;
  f[0]=0;
  t=1;
  a[n]=1e9+11;
  For(i,0,n){
    for(q=p;q<=m&&c[q].fi<a[i+1];++q);
    ll w=i?g[i-1]:0;
    if(p==t){
      g[i]=w;
      For(j,p,q){
        f[j]=w+c[j].fi-a[i];
      }
    }else{
      g[i]=min(w+a[i]-c[t].se,f[p-1]);
      for(int j=t;j<=p-2;++j) upmn(g[i],f[j]+a[i]-c[j+1].se);
      ll u=inf,v=inf;
      For(j,t,p){
        upmn(u,(j==t?w:f[j-1])-c[j].se);
        upmn(v,(j==t?w:f[j-1])-2*c[j].se);
      }
      For(j,p,q){
        f[j]=f[p-1]+c[j].fi-a[i];
        upmn(f[j], u+2*c[j].fi-a[i]);
        upmn(f[j], v+c[j].fi+a[i]);
      }
    }
    t=p;
    p=q;
  }
  ll ans=f[m];
  if(a[n-1]>c[m].fi)ans=min(ans,g[n-1]);
  return ans;
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