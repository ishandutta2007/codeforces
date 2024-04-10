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

struct Point {
  ll x, y;
  Point(ll x, ll y) : x(x), y(y) {}
  Point() : x(0), y(0) {}
  Point operator -(const Point &p) const {
    return Point(x - p.x, y - p.y);
  }
  ll operator *(const Point &p) const {
    return (ll)x * p.x + (ll)y * p.y;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <Point> pt(n);
  for (int i = 0; i < n; ++i) {
    cin >> pt[i].x >> pt[i].y;
  }
  vector <int> ord;
  ord.push_back(0);
  ord.push_back(1);
  for (int i = 2; i < n; ++i) {
    for (int pos = ord.size() - 1; pos >= 0; --pos) {
      int ok = 1;
      if (pos > 0) {
        if ((pt[i] - pt[ord[pos]]) * (pt[ord[pos - 1]] - pt[ord[pos]]) <= 0) {
          ok = 0;
        }
      }
      if (ok) {
        ord.insert(ord.begin() + pos + 1, i);
        break;
      }
    }
  }
  /*for (int i = 1; i + 1 < n; ++i) {
    assert((pt[ord[i - 1]] - pt[ord[i]]) * (pt[ord[i + 1]] - pt[ord[i]]) > 0);
  }*/
  for (auto x : ord) cout << x + 1 << ' ';
}