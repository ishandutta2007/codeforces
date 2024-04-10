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
inline int reduce(int x){return x+(x>>31&mo);}
inline int& inc(int &x,int y){return x=reduce(x+y-mo);}
inline int& dec(int &x,int y){return x=reduce(x-y);}
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
vector<pa> e[N];
int n;
int a[N];
const int pool[]={2,3};
void dfs(int x,int fa=0,int w=0){
  for(auto [y,id]:e[x]){
    if(y==fa)continue;
    a[id]=pool[w];
    dfs(y,x,w^1);
  }
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;++i)e[i].clear();
  for(int i=1;i<n;++i){
    int u,v;
    cin>>u>>v;
    e[u].pb(v,i);
    e[v].pb(u,i);
  }
  int i;
  for(i=1;i<=n;++i){
    if(SZ(e[i])>2) break;
  }
  if(i<=n){
    cout<<"-1\n";
  }else{
    for(i=1;;++i)
      if(SZ(e[i])==1)break;
    dfs(i);
    for(int i=1;i<n;++i)cout<<a[i]<<" \n"[i+1==n];
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