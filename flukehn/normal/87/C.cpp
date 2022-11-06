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
const int N=1e5+11;
int sg[N],s[N];
int f[N];
int vis[N],cnt;
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  for(int i=0;i<N;++i)f[i]=-1;
  sg[1]=0;
  for(int n=2;n<N;++n){
    ++cnt;
    int w=INT_MAX;
    for(int k=2;2*n/k+1-k>=2;++k)if(2*n%k==0){
      int a=(2*n/k+1-k);
      if(a%2)continue;
      a/=2;
      //if(n<=100)dbg(n,a,k);
      int p=s[a-1]^s[a+k-1];
      if(!p)upmn(w,k);
      vis[p]=cnt;
    }
    int i;
    for(i=0;vis[i]==cnt;++i);
    sg[n]=i;
    if(sg[n])f[n]=w;
    s[n]=s[n-1]^sg[n];
  }
  int n;
  while(cin>>n)cout<<f[n]<<"\n";
}