#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  vector<int> v;
  for(int i = 3; i * i + 1 <= 2'000'000'000; i += 2) v.push_back((i * i + 1) / 2);
  for(cin >> t; t; t -= 1){
    //c = (a ^ 2 + 1) / 2
    int n;
    cin >> n;
    cout << upper_bound(v.begin(), v.end(), n) - v.begin() << "\n";
  }
  return 0;
}