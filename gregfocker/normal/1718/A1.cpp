#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
///#define int long long

int solve(vector<int> init) {
  int n=(int)init.size();
  vector<int> v(n+1,0);
  vector<int> dp(n+1,0);
  for (int i=1;i<=n;i++){
    v[i]=v[i-1]^init[i-1];
  }
  for (int i=1;i<=n;i++) {
    dp[i]=dp[i-1]+1;
    for (int j=1;j<i;j++) {
      if (v[i]==v[j-1]) {
        dp[i]=min(dp[i],dp[j-1]+i-j);
      }
    }
  }
  return dp[n];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  ///freopen ("___input___.txt", "r", stdin);


  int tests;
  cin>>tests;
  for(int tc=1;tc<=tests;tc++){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &x:a){
      cin>>x;
    }
    int l=0,sol=0;
    while(l<n){
      if (a[l]==0) {
        l++;
        continue;
      }
      int r=l;
      while (r+1<n&&a[r+1]!=0) r++;
      for (int i=l;i<=r;i++){
        assert(a[i]!=0);
      }
      vector<int> b;
      for (int i=l;i<=r;i++){
        b.push_back(a[i]);
      }
      sol+=solve(b);
      l=r+1;
    }
    cout<<sol<<"\n";
  }

}