
#include <bit>
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;
const int ms = 3000+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[ms];

void solve() {
  string s;
  cin >> s;
  bool hasOne = false;
  for(int i = 0; i < s.size(); i++) {
    if(!hasOne) {
      if(s[i] == '1') {
        i++;
        if(i < s.size() && s[i] == '1') hasOne = true;
      }
    } else {
      if(s[i] == '0') {
        i++;
        if(i < s.size() && s[i] == '0') {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}