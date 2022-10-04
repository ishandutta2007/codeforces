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
    int n;
    cin >> n;
    multiset<ll> have;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      sum += x;
      have.insert(x);
    }
    multiset<ll> cur;
    cur.insert(sum);
    while (!cur.empty()) {
      ll x = *cur.rbegin();
      cur.erase(--cur.end());
      if (have.find(x) != have.end()) {
        have.erase(have.find(x));
      } else if (x >= 2) {
        cur.insert(x / 2);
        cur.insert((x + 1) / 2);
        if (cur.size() > have.size()) break;
      }
    }
    cout << (have.empty() ? "YES" : "NO") << '\n';
  }
}