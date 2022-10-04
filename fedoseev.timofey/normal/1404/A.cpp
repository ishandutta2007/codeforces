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
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> who(k, -1);
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '?') continue;
      int x = s[i] - '0';
      if (who[i % k] == -1) who[i % k] = x;
      if (who[i % k] != x) {
        bad = true;
      }
    }
    if (bad) {
      cout << "NO\n";
      continue;
    }
    vector <int> cnt(2);
    for (int i = 0; i < k; ++i) {
      if (who[i] != -1) ++cnt[who[i]];
    }
    if (cnt[0] <= k / 2 && cnt[1] <= k / 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}