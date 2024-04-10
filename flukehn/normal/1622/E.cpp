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
const int N=10,M=10011;
int n,m;
int x[N];
char s[N][M];
ll ans;
int f[M],p[M],ip[M];
int q[M];
void solve(){
  ans=-1;
  cin>>n>>m;
  For(i,0,n)cin>>x[i];
  For(i,0,n)cin>>s[i];
  For(i,0,n)For(j,0,m)s[i][j]-='0';
  For(i,0,m)p[i]=i;
  For(i,0,1<<n){
    For(j,0,m) f[j]=0;
    // 0 x-r > 0
    // 1 r-x > 0
    For(j,0,n) For(k,0,m) if(s[j][k]) f[k] += (i>>j&1) ? +1 : -1;
    sort(p,p+m,[](int i,int j){
        return f[i]<f[j];
        });
    For(i,0,m)ip[p[i]]=i;
    ll tmp=0;
    For(j,0,n){
      ll w=0;
      For(k,0,m) if(s[j][k]) w+=ip[k]+1;
      tmp+=abs(w-x[j]);
    }
    if(upmx(ans,tmp)) {
      For(j,0,m) q[j]=ip[j];
    }
  }
  dbg(ans);
  For(i,0,m)cout<<q[i]+1<<" \n"[i+1==m];
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