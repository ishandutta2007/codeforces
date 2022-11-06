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
const int N=1e5+5;
const int S=512;
int a[N];
struct Block{
  int b[S];
  int f[N],g[N];
  int fa(int i){
    return f[i]==i?i:f[i]=fa(f[i]);
  }
  int t,mx;
  void build(int *a,int n){
    assert(n<=S);
    For(i,0,N){
      f[i]=i;
      g[i]=0;
    }
    t=0;
    mx=0;
    For(i,0,n){
      b[i]=a[i];
      g[a[i]]+=1;
      mx=max(mx,a[i]);
    }
  }
  void merge_to(int x,int y){
    x=fa(x);
    y=fa(y);
    if(x!=y){
      f[x]=y;
      g[y]+=g[x];
      g[x]=0;
    }
  }
  
  void modify(int x){
    if(mx>=2*x){
      for(int i=t+1;i<=t+x;++i)
        merge_to(i,i+x);
      t+=x;
      mx-=x;
    }else if(mx>x){
      //assert(mx>x);
      for(int i=t+x+1;i<=t+mx;++i){
        merge_to(i,i-x);
      }
      mx=x;
    }
  }
  void modify(int p,int x){
    int s=fa(b[p]);
    if(s-t<=x) return;
    g[s]-=1;
    g[s-x]+=1;
    b[p]=s-x;
  }
  int count(int x){
    //dbg(x,t,mx,g[x+t],g[1]);
    if(x>mx) return 0;
    return g[x+t];
  }
  int count(int p,int x){
    //dbg(b[p],fa(b[p]),t,x,fa(b[p])-t==x);
    return fa(b[p])-t==x;
  }
};
Block b[200];
int bel(int x){return x/S;}
int n,Q;
void solve(){
  For(i,0,n)cin>>a[i];
  for(int i=0;i*S<n;++i){
    b[i].build(a+i*S,min(S,n-i*S));
  }
  while(Q--){
    int op,l,r,x;
    cin>>op>>l>>r>>x;
    if(op==1){
      l-=1;
      int u=bel(l),v=bel(r-1);
      if(u==v){
        For(i,l,r) b[u].modify(i%S,x);
      }else{
        For(i,l,u*S+S) b[u].modify(i%S,x);
        For(i,v*S,r) b[v].modify(i%S,x);
        For(i,u+1,v) b[i].modify(x);
      }
    }else{
      l-=1;
      int u=bel(l),v=bel(r-1);
      int ans=0;
      if(u==v){
        //dbg("ok");
        For(i,l,r) ans+=b[u].count(i%S,x);
      }else{
        For(i,l,u*S+S) {
          ans+=b[u].count(i%S,x);
          //if(b[u].count(i%S,x)) dbg(i+1);
        }
        For(i,v*S,r) {
          ans+=b[v].count(i%S,x);
          //if(b[v].count(i%S,x)) dbg(i+1);
        }
        For(i,u+1,v) {
          //dbg(i*S+1,i*S+S);
          int w=b[i].count(x);
          ans+=w;
        }
      }
      cout<<ans<<"\n";
    }
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  while(cin>>n>>Q)solve();
}