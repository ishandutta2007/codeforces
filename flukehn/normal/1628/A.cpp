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
const int N=2e5+11;
int a[N];
queue<int> q[N];
int n;
void solve(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i) q[a[i]].push(i);
  vector<int> b;
  for(int i=1;i<=n;){
    dbg(i);
    int j, p=i;
    for(j=0;!q[j].empty();++j){
      p=max(p, q[j].front());
    }
    b.push_back(j);
    
    for(;i<=p;++i)
      q[a[i]].pop();
  }
  int m=b.size();
  cout<<m<<"\n";
  For(i,0,m)cout<<b[i]<<" \n"[i+1==m];
}
int main(){
#ifdef flukehn
  //freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}