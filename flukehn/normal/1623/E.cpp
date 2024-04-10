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
char s[N];
int ls[N],rs[N];
int n,k;
struct P{
  char u,v;
  P(char _u=-1,char _v=-1):u(_u),v(_v){if(~_u) assert(_u!=_v);}
  P operator+(const P&t)const{
    if(~v) return *this;
    if(u==-1) return t;
    if(u!=t.u) return P(u,t.u);
    return P(u,t.v);
  }
};
int cnt;
P a[N];
int b[N];
int fa[N];
void dfs(int x){
  if(x){
    dfs(rs[x]);
    a[x]=P(s[x-1],-1)+a[b[cnt]];
    b[++cnt]=x;
    dfs(ls[x]);
  }
}
int fp[N];
int dp(int x,int dep){
  if(dep>k) return 0;
  if(ls[x] && dp(ls[x],dep+1)) {
    fp[x]=1;
  }else{
    P w=a[x];
   // P w=P(s[x-1],-1)+a[rs[x]];
    //if(fa[x] && ls[fa[x]]==x) w=w+P(s[fa[x]-1],-1)+a[rs[fa[x]]];
    if(w.v>w.u){
      dbg(x,w.u,w.v);
      fp[x]=1;
      k-=dep;
    }
  }
  if(fp[x] && rs[x]) dp(rs[x],1);
  return fp[x];
}
string ans;
void dfs2(int x){
  if(ls[x])dfs2(ls[x]);
  For(i,0,fp[x]+1) ans+=s[x-1];
  if(rs[x])dfs2(rs[x]);
}
string solve(){
  cnt=0;
  cin>>s;
  for(int i=1;i<=n;++i)cin>>ls[i]>>rs[i];
  for(int i=1;i<=n;++i){
    if(ls[i])fa[ls[i]]=i;
    if(rs[i])fa[rs[i]]=i;
  }
  for(int i=0;i<=n;++i)fp[i]=0;
  dfs(1);
  dp(1,1);
  ans.clear();
  dfs2(1);
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n>>k)cout<<solve()<<"\n";
}