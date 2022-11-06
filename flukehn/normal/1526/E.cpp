#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=400'011;
int jc[N],jcv[N];
int C(int a,int b){return a<b?0:1ll*jc[a]*jcv[b]%mo*jcv[a-b]%mo;}
int s[N/2];
int rk[N/2];
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  jc[0]=1;
  For(i,1,N)jc[i]=1ll*i*jc[i-1]%mo;
  jcv[N-1]=Pow(jc[N-1],mo-2);
  for(int i=N-1;i>=1;--i)jcv[i-1]=1ll*jcv[i]*i%mo;
  int n,k;
  while(cin>>n>>k){
    For(i,0,n)cin>>s[i];
    For(i,0,n)rk[s[i]]=i;
    rk[n]=-1;
    int tot=0;
    For(i,1,n)if(rk[s[i]+1]>rk[s[i-1]+1])++tot;
    cout<<C(tot+k,n)<<"\n";
  }
}