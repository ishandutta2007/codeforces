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
const int mo=1e9+7;
const int N=2e5+11;
int fib[N];
int sf[N];
void init(){
  fib[0]=1;
  fib[1]=1;
  for(int i=2;i<N;++i)
    fib[i]=(fib[i-1]+fib[i-2])%mo;
  sf[0]=1;
  for(int i=1;i<N;++i)
    sf[i]=(sf[i-1]+fib[i])%mo;
}
int a[N];
int n,m;
int solve(){
  For(i,0,n)cin>>a[i];
  sort(a,a+n);
  int ans=0;
  set<int> S;
  For(i,0,n) {
    int x=a[i];
    int y=0;
    while(x)x/=2,y+=1;
    x=a[i];
    while(x&&!S.count(x)){
      if(x&1)x/=2;
      else if(x%4==0)x/=4;
      else break;
    }
    if(!S.count(x)) {
      S.insert(a[i]);
      if(y<=m)ans=(ans+sf[m-y])%mo;
    }
  }
  return ans%mo;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  init();
  while(cin>>n>>m) {
    cout<<solve()<<"\n";
  }
}