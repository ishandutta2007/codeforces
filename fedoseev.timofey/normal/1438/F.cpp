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

mt19937 rnd(time(0));

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int h;
  cin >> h;
  int n = (1 << h) - 1;
  vector <int> cnt(n);
  for (int i = 0; i < 420; ++i) {
    int u, v, w;
    do {
      u = rnd() % n, v = rnd() % n, w = rnd() % n;
    } while (u == v || u == w || v == w);
    cout << "? " << u + 1 << ' ' << v + 1 << ' ' << w + 1 << endl;
    int x;
    cin >> x;
    --x;
    ++cnt[x];
  }
  vector <int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&] (int u, int v) {
    return cnt[u] > cnt[v];
  });
  int a = p[0], b = p[1];
  for (int c = 0; c < n; ++c) {
    if (c == a || c == b) continue;
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    int x;
    cin >> x;
    --x;
    if (x == c) {
      cout << "! " << x + 1 << endl;
      return 0;
    }
  }
  assert(false);
}