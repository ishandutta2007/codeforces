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
const int N=2e5+11;
int a[N];
int s[N];
int n;
const int M=22;
int b[M];
int F[N];
int solve(){
  cin>>n;
  for(int i=1;i<=n;++i)a[i]=0;
  for(int i=1;i<=n;++i){
    int x;
    cin>>x;
    a[x]+=1;
  }
  for(int i=1;i<=n;++i)
    s[i]=s[i-1]+a[i];
  int ans=1+1+F[s[n]];
  for(int i=0;i<M;++i) b[i]=0;
  for(int i=1;i<=n;++i){
    for(int j=0;j<M;++j){
      while(s[i]-s[b[j]]>(1<<j)) b[j]+=1;
      upmn(ans, F[s[n]-s[i]] + F[s[i]-s[b[j]]] + F[s[b[j]]]);
    }
  }
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t=0;
  For(i,0,N) {
    while((1<<t)<i)t+=1;
    F[i]=(1<<t)-i;
  }
  cin>>t;
  while(t--)
    cout<<solve()<<"\n";
}