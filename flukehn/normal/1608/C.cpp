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
const int N=1e5+11;
int n;
pa a[N],b[N];
int h(int *f,int x){return f[x]==x?x:f[x]=h(f,f[x]);}
int f[N],g[N];
char vis[N];
//int a[N],b[N];
int p[N],q[N];
void wk(int t,int i){
  if(!t){
    vis[a[i].se]=1;
    f[i]=h(f,i+1);
    int j=q[a[i].se];
    for(int k=h(g,j+1);k<=n&&k;k=h(g,k+1)){
      wk(1,k);
    }
  }else{
    vis[b[i].se]=1;
    g[i]=h(g,i+1);
    int j=p[b[i].se];
    for(int k=h(f,j+1);k<=n&&k;k=h(f,k+1)){
      wk(0,k);
    }
  }
}
void work(){
  cin>>n;
  For(i,0,n+3)vis[i]=0;
  For(i,1,n+1){
    cin>>a[i].fi;
    a[i].se=i;
  }
  For(i,1,n+1){
    cin>>b[i].fi;
    b[i].se=i;
  }
  sort(a+1,a+n+1);
  sort(b+1,b+n+1);
  For(i,1,n+1)p[a[i].se]=i;
  For(i,1,n+1)q[b[i].se]=i;
  For(i,0,n+3)f[i]=g[i]=i;
  wk(0,n);
  wk(1,n);
  For(i,1,n+1)vis[i]+='0';
  puts(vis+1);
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)work();
}