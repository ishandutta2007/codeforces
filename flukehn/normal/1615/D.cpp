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
int n,m;
int f[N],g[N],h[N];
int fa(int i){
  if(f[i]==i) return f[i];
  int x=f[i],y=fa(f[i]);
  g[i]=g[i]^g[x];
  f[i]=y;
  return y;
}
using E=tuple<int,int,int>;
void solve(){
  cin>>n>>m;
  for(int i=1;i<=n;++i)f[i]=i,g[i]=0,h[i]=0;
  vector<E> ans,tmp;
  int flag=1;
  For(i,1,n){
    int x,y,w;
    cin>>x>>y>>w;
    if(w<0){
      tmp.pb(x,y,w);
    }else{
      ans.pb(x,y,w);
      int u=fa(x);
      int v=fa(y);
      if(u!=v){
        f[u]=v;
        g[u]=g[x]^g[y]^__builtin_popcount(w)%2;
        //dbg(u,v,w%2);
      }else{
        if(g[x]^g[y]^__builtin_popcount(w)%2){
          //dbg(i,x,y,g[x],g[y],w%2);
          flag=0;
        }
      }
    }
  }
  For(i,0,m){
    int x,y,w;
    cin>>x>>y>>w;
    int u=fa(x),v=fa(y);
    //dbg(x,y,u,v);
    if(u!=v){
      f[u]=v;
      g[u]=g[x]^g[y]^w;
      //dbg(u,v,w%2);
    }else{
      if(g[x]^g[y]^w){
        //dbg(i,x,y,g[x],g[y],w%2);
        flag=0;
      }
    }
  }
  if(!flag) {
    cout<<"NO\n";
  }else{
    cout<<"YES\n";
    for(auto [x,y,w]:tmp){
      int u=fa(x),v=fa(y);
      if(u!=v){
        f[u]=v;
        g[u]=0;
      }else{

      }
      fa(u),fa(v);
      w=g[x]^g[y];
      ans.pb(x,y,w);
    }
    for(auto [x,y,w]:ans)cout<<x<<" "<<y<<" "<<w<<"\n";
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