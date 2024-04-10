#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int mo=998244353;
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
inline int reduce(int x){return x+(x>>31&mo);}
inline int& inc(int &x,int y){return x=reduce(x+y-mo);}
inline int& dec(int &x,int y){return x=reduce(x-y);}

const int N=720720;
int main(){
#ifdef flukehn
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int n,a,x,y,M,k;
  cin>>n>>a>>x>>y>>k>>M;
  vector<int> f(N,0);
  int ans=0;
  const int in=Pow(n,mo-2);
  for(int i=0;i<n;++i){
    int b=a%N;
    inc(ans,a-b);
    f[b]+=1;
    a=(1LL*a*x+y)%M;
  }
  //dbg(ans);
  ans=1LL*ans*k%mo;
  for(int i=1;i<=k;++i) {
    vector<int> g(N,0);
    for(int j=0;j<N;++j){
      inc(ans, 1LL*f[j]*j%mo);
      inc(g[j], 1LL*f[j]*(mo+1-in)%mo);
      inc(g[j-j%i], 1LL*f[j]*in%mo);
    }
    f=move(g);
  }
  ans=1LL*ans*in%mo;
  for(int i=0;i<k;++i) ans=1LL*ans*n%mo;
  cout<<ans<<"\n";
}