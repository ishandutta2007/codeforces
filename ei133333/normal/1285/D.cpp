#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  sort(a.begin(),a.end());

  function<Int(Int, Int, Int)> dfs=
      [&](Int l,Int r,Int d)->Int{
        Int x=(a[l]>>d)&1,y=(a[r-1]>>d)&1;
        if(d==0) return x!=y;
        if(x==y) return dfs(l,r,d-1);
        Int m=upper_bound(a.begin(),a.end(),a[l]|((1<<d)-1))-a.begin();
        assert(l<m&&m<r);
        return min(dfs(l,m,d-1),dfs(m,r,d-1))+(1<<d);
      };

  cout<<dfs(0,n,30)<<endl;
  return 0;
}