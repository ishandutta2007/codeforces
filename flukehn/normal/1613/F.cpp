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
const int N=250'011;
int jc[N],jcv[N];
int n;
vector<int> e[N];
int sz[N],sc[N];
void dfs(int x){
  sz[x]=1;
  sc[x]=0;
  for(int y:e[x]){
    e[y].erase(find(all(e[y]),x));
    dfs(y);
    sz[x]+=sz[y];
    if(sz[y]>sz[sc[x]])sc[x]=y;
  }
}
namespace Poly{
#define clr(x) memset(x,0,sizeof x)
#define per(i,a,b) for(int i=b,i##_end=a;i>=i##_end;--i)
  const int N=1e6+11,mo=998244353,G=3;
  int Pow(int a,int b){
    int r=1;
    for(;b;b>>=1,a=1ll*a*a%mo)
      if(b&1)r=1ll*r*a%mo;
    return r;
  }
  void dft(int *a,int n){
    int i,j,l;
    for(i=j=0;i<n;++i){
      if(i>j)swap(a[i],a[j]);
      for(l=n>>1;(j^=l)<l;l>>=1);
    }
    for(l=1;l<n;l<<=1){
      int wn=Pow(G,(mo-1)/l/2);
      for(i=0;i<n;i+=l<<1){
        int w=1;
        for(j=0;j<l;++j,w=1ll*w*wn%mo){
          int x=a[i+j],y=1ll*w*a[i+j+l]%mo;
          a[i+j]=(x+y)>=mo?x+y-mo:x+y;;
          a[i+j+l]=x-y<0?x-y+mo:x-y;;
        }
      }
    }
  }
  void idft(int *a,int n){
    dft(a,n);
    reverse(a+1,a+n);
    int m=Pow(n,mo-2);
    For(i,0,n)a[i]=1ll*a[i]*m%mo;
  }
  void mul(int *a,int A,int *b,int B,int *c){
    int m=1;
    while(m<A+B)m<<=1;
    int x[m],y[m];
    clr(x),clr(y);
    For(i,0,A)x[i]=a[i];
    For(i,0,B)y[i]=b[i];
    dft(x,m),dft(y,m);
    For(i,0,m)c[i]=1ll*x[i]*y[i]%mo;
    idft(c,m);
  }
}
vector<int> solve(int l,int r){
  dbg(l,r);
  if(l+1==r){
    vector<int> ret;
    ret.push_back(1);
    if(SZ(e[l]))ret.push_back(SZ(e[l]));
    return ret;
  }
  int m=(l+r)>>1;
  auto u=solve(l,m);
  auto v=solve(m,r);
  vector<int> f((r-l+3)*8);
  dbg(l,r);
  Poly::mul(&u[0],SZ(u),&v[0],SZ(v),&f[0]);
  f.resize(r-l+3);
  return f;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  jc[0]=1;
  For(i,1,N)jc[i]=1ll*jc[i-1]*i%mo;
  jcv[N-1]=Pow(jc[N-1],mo-2);
  for(int i=N-1;i>=1;--i)jcv[i-1]=1ll*jcv[i]*i%mo;
  while(cin>>n){
    dbg(n);
    For(i,1,n+1)e[i].clear();
    For(i,1,n){
      int x,y;
      cin>>x>>y;
      e[x].pb(y);
      e[y].pb(x);
    }
    dfs(1);
    int ans=0;
    auto g=solve(1,n+1);
    For(i,0,SZ(g))debug("%d%c",g[i]," \n"[i+1==i_end]);
    For(i,0,SZ(g)){
      if(i>=n)break;
      dbg(i,g[i],n,n-i,jc[n-i]);
      int t=1ll*g[i]*jc[n-i]%mo;
      if(i%2)dec(ans,t);
      else inc(ans,t);
    }
    cout<<ans<<"\n";
  }
}