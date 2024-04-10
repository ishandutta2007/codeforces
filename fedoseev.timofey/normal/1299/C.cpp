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
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector <pair <ll, int>> st;
  for (int i = 0; i < n; ++i) {
    ll cs = a[i], cnt = 1;
    while (!st.empty() && (ld)(st.back().first + cs) / (cnt + st.back().second) <= (ld)st.back().first / st.back().second) {
      cs += st.back().first;
      cnt += st.back().second;
      st.pop_back();
    } 
    st.push_back({cs, cnt});
  }
  for (auto p : st) {
    ld cur = (ld)p.first / p.second;
    for (int i = 0; i < p.second; ++i) {
      cout << fixed << setprecision(20) << cur << '\n';
    }
  }
}