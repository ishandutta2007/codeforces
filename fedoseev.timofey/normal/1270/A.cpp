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
    int n, a, b;
    cin >> n >> a >> b;
    bool fl = false;
    for (int i = 0; i < a; ++i) {
      int x;
      cin >> x;
      fl |= (x == n);
    }
    for (int i = 0; i < b; ++i) {
      int x;
      cin >> x;
    }
    cout << (fl ? "YES" : "NO") << '\n';
  }
}