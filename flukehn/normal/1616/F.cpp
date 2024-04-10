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
#define dbg(...) 0//cerr<<"L"<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
#define debug(...) 0//cerr<<__VA_ARGS__//fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=66,M=266;
int e[N][N],c[N][N];
int n,m;
int d[M];
int f[114514][M];
int vis[M];
void solve(){
  memset(e,0,sizeof e);
  memset(c,0,sizeof c);
  memset(vis,0,sizeof vis);
  memset(f,0,sizeof f);
  cin>>n>>m;
  for(int i=1;i<=m;++i){
    int u,v,w;
    cin>>u>>v>>w;
    e[u][v]=e[v][u]=i;
    c[u][v]=c[v][u]=w;
    d[i]=w;
  }
#define GG {cout<<"-1\n";return;}
  int tot=0;
  for(int i=1;i<=n;++i)
    for(int j=i+1;j<=n;++j)
      for(int k=j+1;k<=n;++k)
        if(e[i][j]&&e[j][k]&&e[k][i]){
          vector<int> p;
          int w=0;
          auto D=[&](int z,int i){
            if(z<0)p.pb(i);
            else w=(w+z)%3;
          };
          D(c[i][j],e[i][j]);
          D(c[j][k],e[j][k]);
          D(c[k][i],e[k][i]);
          if(!SZ(p)){
            if(w) GG;
            continue;
          }
          ++tot;
          //for(int k=1;k<=m+1;++k)f[tot][k]=0;
          for(int z:p) f[tot][z]=1;
          f[tot][m+1]=(3-w)%3;
        }
  //dbg(tot);
  int p=1;
  for(int i=1;i<=m;++i){
    //dbg(i);
    for(int j=p;j<=tot;++j)
      if(f[j][i]){
        swap(f[j],f[p]);
        break;
      }
    if(!f[p][i])continue;
    vis[i]=1;
    int z=f[p][i];
    //f[p][i]=1;
    for(int k=i;k<=m+1;++k) f[p][k]=f[p][k]*z%3;
    assert(f[p][i]==1);
    for(int j=p+1;j<=tot;++j){
      if(!f[j][i])continue;
      int w=f[j][i];
      for(int k=i;k<=m+1;++k) f[j][k]=(6+f[j][k]-w*f[p][k])%3;
    }
    ++p;
  }
  //dbg(p);
  for(int i=p-1;i>=1;--i){
    int z;
    for(z=1;!f[i][z];++z);
    assert(f[i][z]==1);
    //dbg(i,z,f[i][m+1]);
    d[z]=f[i][m+1];
    for(int j=i-1;j>=1;--j)
      if(f[j][z]){
        int w=f[j][z];
        for(int k=1;k<=m+1;++k)f[j][k]=(6+f[j][k]-w*f[i][k])%3;
      }
  }
  //for(int i=1;i<p;++i)for(int j=1;j<=m+1;++j)debug(f[i][j]<<" \n"[j==m+1]);
  //for(int i=1;i<=m;++i) debug(d[i]<<" \n"[i==m]);
  for(int i=1;i<=m;++i)if(d[i]<0)d[i]=0;
  for(int i=p;i<=tot;++i){
    int w=(3-f[i][m+1])%3;
    for(int j=1;j<=m;++j)
      if(f[i][j])w=(w+d[j]*f[i][j])%3;
    if(w) GG;
  }
  for(int i=1;i<=m;++i)if(!d[i])d[i]=3;
  for(int i=1;i<=m;++i) cout<<d[i]<<" \n"[i==m];
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