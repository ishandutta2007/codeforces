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
const int mo=1e9+7;
constexpr int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
inline int reduce(int x){return x+(x>>31&mo);}
inline int& inc(int &x,int y){return x=reduce(x+y-mo);}
inline int& dec(int &x,int y){return x=reduce(x-y);}
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e6+11;
int jc[N],jcv[N];
int p2[N];
void init(){
  p2[0]=1;
  for(int i=1;i<N;++i) p2[i]=2*p2[i-1]%mo;
  jc[0]=1;
  For(i,1,N)jc[i]=1LL*jc[i-1]*i%mo;
  jcv[N-1]=Pow(jc[N-1],mo-2);
  for(int i=N-1;i>=1;--i)jcv[i-1]=1LL*jcv[i]*i%mo;
}
int C(int a,int b){
  return a<b||b<0?0:1LL*jc[a]*jcv[b]%mo*jcv[a-b]%mo;
}

int solve(){
  int n,m,k;
  cin>>n>>m>>k;
  if(n==0||m==0) return 0;
  if(n==m) return 1LL*n*k%mo;
  int ans=0;
  for(int i=1;i<=m&&i<n;++i){
    int x=n-i-1,y=m-i;
    //dbg(i*p2[i],x,y,C(x,y),C(x+y,x+1));
    ans=(ans+1LL*i*p2[i]%mo*C(x,y))%mo;
  }
  dbg(ans);
  if(ans<0)ans+=mo;
  ans=1LL*ans*k%mo;
  ans=1LL*ans*Pow(p2[n],mo-2)%mo;
  return ans;
  /*
  for(int i=0;i<=n;++i){
    for(int j=0;j<=m&&j<=i;++j){
      if(!i||!j) f[i][j]=0;
      else if(i==j){
        f[i][j]=i;
      }else{
        f[i][j]=1LL*iv2*(f[i-1][j]+f[i-1][j-1])%mo;
      }
    }
  }
  return 1LL*k*f[n][m]%mo;*/
}
int main(){
#ifdef flukehn
  //freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  init();
  int t;
  cin>>t;
  while(t--){
    cout<<solve()<<"\n";
  }
}