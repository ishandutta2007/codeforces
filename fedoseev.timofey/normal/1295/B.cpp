#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
  
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int bal = 0;
    map <int, int> cnt;
    ++cnt[bal];
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') ++bal;
      else --bal;
      if (i + 1 < n) ++cnt[bal];
    }
    if (bal == 0 && cnt.count(x)) {
      cout << "-1\n";
      continue;
    } else if (bal == 0) {
      cout << "0\n";
      continue;
    }
    ll ans = 0;
    for (auto p : cnt) {
      if ((x - p.first) % bal == 0 && (x - p.first) / bal >= 0) {
        ans += p.second;
      }
    }
    cout << ans << '\n';
  } 
}