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
const int N=7011;
int k[2],s[2][N];
int n;
int f[2][N],g[2][N];
int vis[2][N];
void solve(){
  For(i,0,2){
    cin>>k[i];
    For(j,0,k[i])cin>>s[i][j];
  }
  memset(f,-1,sizeof f);
  For(i,0,2)For(j,0,n)g[i][j]=k[i];
  memset(vis,0,sizeof vis);
  vis[0][0]=1;
  vis[1][0]=1;
  f[0][0]=0;
  f[1][0]=0;
  queue<pa> q;
  q.push(pa(0,0));
  q.push(pa(1,0));
  while(!q.empty()){
    auto [o,x]=q.front();
    q.pop();
    int w=f[o][x];
    o^=1;
    For(i,0,k[o]){
      int y=(x+n-s[o][i])%n;
      if(vis[o][y])continue;
      if(!w){
        f[o][y]=1;
        vis[o][y]=1;
        q.push(pa(o,y));
      }else{
        if(--g[o][y]==0){
          vis[o][y]=1;
          f[o][y]=0;
          q.push(pa(o,y));
        }
      }
    }
  }
  For(i,0,2){
    For(j,1,n){
      const string x[]={"Loop","Lose","Win"};
      cout<<x[f[i][j]+1]<<" \n"[j+1==j_end];
    }
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n)solve(); 
}