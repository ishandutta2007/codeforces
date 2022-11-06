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
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1011;
const int M=31;
int n;
int a[N][N];
int solve(){
  int ans=0;
  cin>>n;
  For(i,0,n)For(j,0,n) a[i][j]=0;
  For(i,0,n){
    For(j,0,n){
      int x;
      cin>>x;
      if(i && !a[i-1][j]) {
        a[i-1][j]=1;
        if(j)a[i][j-1]^=1;
        a[i][j+1]^=1;
        a[i+1][j]^=1;
        ans^=x;
      }
    }
  }
  
  return ans;
}
int main(){
#ifdef flukehn
  //freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    cout<<solve()<<"\n";
  }
}