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
const int N=1e6+11;
int n;
int a[N];
int c[N];
int f[N];
void add(int x,int v){
  if(!x)return;
  for(;x<=n;x+=x&-x)
    c[x]+=v;
}
int qry(int x){
  int r=0;
  for(;x;x-=x&-x)
    r+=c[x];
  return r;
}
int kth(int k){
  int p=0;
  for(int j=19;j>=0;--j){
    if(p+(1<<j)>n||c[p+(1<<j)]>=k)continue;
    p+=1<<j;
    k-=c[p];
  }
  return p+1;
}
using E=tuple<int,int,int>;
vector<E> Q[N];
vector<int> e[N];
//queue<int> g[N];
vector<int> g[N];
int ans[N];
void dfs(int x){
  add(f[a[x]],-1);
  add(++f[a[x]],1);
  g[f[a[x]]].pb(a[x]);
  int tot=qry(n);
  for(auto [l,k,id]:Q[x]){
    int cnt=qry(l-1);
    if(k>tot-cnt)ans[id]=-1;
    else{
      l=kth(cnt+k);
      /*int r=n;
      while(l<r){
        int m=(l+r)>>1;
        if(qry(m)-cnt>=k)r=m;
        else l=m+1;
      }*/
      while(f[g[l].back()]!=l)g[l].pop_back();
      ans[id]=g[l].back();
    }
  }
  for(int y:e[x])
    dfs(y);
  add(f[a[x]],-1);
  add(--f[a[x]],1);
  if(f[a[x]])g[f[a[x]]].pb(a[x]);
}
void work(){
  int q;
  cin>>n>>q;
  For(i,1,n+1)e[i].clear();
  For(i,1,n+1)Q[i].clear();
  For(i,1,n+1)g[i].clear();//while(!g[i].empty())g[i].pop();
  For(i,1,n+1)cin>>a[i];
  For(i,2,n+1){
    int p;
    cin>>p;
    e[p].pb(i);
  }
  For(i,0,q){
    int v,l,k;
    cin>>v>>l>>k;
    Q[v].pb(l,k,i);
  }
  dfs(1);
  For(i,0,q)cout<<ans[i]<<" \n"[i+1==i_end];
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)
    work();
}