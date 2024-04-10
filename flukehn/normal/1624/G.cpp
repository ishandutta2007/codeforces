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
int f[N];
int fa(int i){return f[i]==i?i:f[i]=fa(f[i]);}
void init(){
  for(int i=1;i<=n;++i)f[i]=i;
}
int u[N],v[N],w[N];
int ig[N];
int solve(){
  int ans=0;
  cin>>n>>m;
  For(i,0,m) ig[i]=0;
  For(i,0,m)cin>>u[i]>>v[i]>>w[i];
  for(int i=30;i>=0;--i){
    init();
    int tot=0;
    For(j,0,m)
      if(!ig[j]&&(~w[j]>>i&1)){
        int x=fa(u[j]);
        int y=fa(v[j]);
        
        if(x!=y){
          tot+=1;
          f[x]=y;
        }
      }
   // dbg(tot,n-1);
    if(tot==n-1){
      For(j,0,m)if(w[j]>>i&1)ig[j]=1;
    }else{
      ans+=1<<i;
    }
  }
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)cout<<solve()<<"\n";

}