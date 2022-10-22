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
  map<int, int> kek;

  for (int i=1;i<=n;i++) {
    if(i-2>=0){
      int j=i-2;
      if(kek.count(v[j])){
        kek[v[j]]=min(kek[v[j]],dp[j]-j-1);
      }else{
        kek[v[j]]=dp[j]-j-1;
      }
    }
    dp[i]=dp[i-1]+1;
    if(kek.count(v[i])){
      dp[i]=min(dp[i],kek[v[i]]+i);
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