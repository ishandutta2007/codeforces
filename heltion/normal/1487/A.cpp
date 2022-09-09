#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;
    cout << n - count(v.begin(), v.end(), *min_element(v.begin(), v.end())) << "\n";
  }
  return 0;
}