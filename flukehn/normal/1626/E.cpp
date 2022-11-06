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
const int N=3e5+11;
int c[N],a[N];
int tot;
int n;
vector<int> e[N];
int s[N];
int fa[N];
void dfs(int x){
  s[x]=c[x];
  for(int y:e[x]){
    if(y==fa[x])continue;
    fa[y]=x;
    dfs(y);
    s[x]+=s[y];
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;++i)cin>>c[i];
  for(int i=1;i<n;++i){
    int x,y;
    cin>>x>>y;
    e[x].pb(y);
    e[y].pb(x);
  }
  for(int i=1;i<=n;++i)tot+=c[i];
  dfs(1);
  queue<int> q;
  for(int x=1;x<=n;++x)
    if(c[x]) {
      a[x]=1;
      q.push(x);
    }
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(int y:e[x]){
      if(a[y])continue;
      int fl=0;
      if(c[x]==1){
        fl=1;
      }else{
        if(x==fa[y]) fl=(tot-s[y]>=2);
        else fl=(s[x]>=2);
      }
      if(fl){
        a[y]=1;
        q.push(y);
      }
    }
  }
  for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
}