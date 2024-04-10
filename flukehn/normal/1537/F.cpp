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
const int N=2e5+11;
vector<int> e[N];
int n,m;
ll t[N];
int c[N];
int flag;
void dfs(int x){
  for(int y:e[x]){
    if(c[y]){
      if(c[y]==c[x])flag=1;
    }else{
      c[y]=-c[x];
      dfs(y);
      t[x]-=t[y];
    }
  }
}
int work(){
  cin>>n>>m;
  For(i,1,n+1)cin>>t[i];
  For(i,1,n+1){
    int v;
    cin>>v;
    t[i]-=v;
  }
  For(i,1,n+1)e[i].clear();
  For(i,0,m){
    int u,v;
    cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  ll sum=0;
  For(i,1,n+1)sum+=t[i];
  if(sum%2)return 0;
  For(i,0,n+1)c[i]=0;
  flag=0;
  c[1]=1;
  dfs(1);
  dbg(n);
  For(i,1,n+1)debug("%d%c",c[i]," \n"[i+1==i_end]);
  return t[1]==0||flag;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)
    cout<<(work()?"YES":"NO")<<"\n";
}