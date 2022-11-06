
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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> dif;
  vector<int> cnt(26);
  for(int i = 0; i < n; i++) {
    if(s[i] != t[i]) dif.emplace_back(i);
    else {
      cnt[s[i]-'a']++;
    }
  }
  if(dif.size() == 0) {
    for(int i = 0; i < 26; i++) {
      if(cnt[i] > 1) {
        cout << "Yes" << endl;
        return;
      }
    }
    cout << "No" << endl;
  } else if(dif.size() == 2) {
    if(t[dif[0]] == t[dif[1]] && s[dif[0]] == s[dif[1]]) {
    cout << "Yes" << endl;
    return;
    }
  }
    cout << "No" << endl;
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