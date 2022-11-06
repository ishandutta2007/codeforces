#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define endl '\n'
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  ll t;
  cin >> t;
 
  ll n, k;
  while(t--){
    cin >> n >> k;
 
    ll ans = 0;
 
    vector<ll> vec(n);
    vector<ll> sum(n); //[0, i)
    for(int i = 0 ; i < n ; i++){
      cin >> vec[i];
      sum[i] += vec[i];
      if(i > 0) sum[i] += sum[i-1];
    }
 
    if(k >= n){
      ans += sum.back();
      if(n == 1){
        ans += k-1;
      }else{
        ans += k-n;
 
        ll r = k-1;
        ll l = r - (n - 1);
 
        ans += r*(r+1)/2;
        ans -= l*(l+1)/2;
 
      }
    }else{
      // cout <<  k  << " " << n << endl;
      for(int i = 0 ; i+k-1 < n ; i++){
        ll r = sum[i+k-1];
        if(i > 0) r -= sum[i-1];
        ans = max(ans, r);
      }
      ans += (k-1)*(k)/2;
    }
 
    cout << ans << endl;
  }
 
  return 0;
}