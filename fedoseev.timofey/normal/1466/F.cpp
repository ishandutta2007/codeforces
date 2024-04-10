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
 
const int md = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m; 
  vector <int> pw(n + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = mul(pw[i - 1], 2);
  vector <int> p(m);
  vector <int> hv(m);
  vector <int> sz(m);
  for (int i = 0; i < m; ++i) {
    p[i] = i;
    hv[i] = 0;
    sz[i] = 1;
  }
  function <int(int)> get = [&] (int a) {
    return (a == p[a] ? a : p[a] = get(p[a]));
  };
  auto join = [&] (int a, int b) {
    a = get(a);
    b = get(b);
    p[a] = b;
    hv[b] = hv[a] | hv[b];
    sz[b] += sz[a];
  };  
  vector <int> ans;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    if (k == 1) {
      int x;
      cin >> x;
      --x;
      if (!hv[get(x)]) {
        ans.push_back(i);
        hv[get(x)] = 1;
      }
    } else {
      int x, y;
      cin >> x >> y;
      --x, --y;
      if (get(x) != get(y) && (!hv[get(x)] || !hv[get(y)])) {
        ans.push_back(i);
        join(x, y);
      }
    }
  }
  int cnt = 1;
  for (int i = 0; i < m; ++i) {
    if (get(i) == i) {
      if (hv[i]) cnt = mul(cnt, pw[sz[i]]);
      else cnt = mul(cnt, pw[sz[i] - 1]);
    }
  }
  cout << cnt << ' ' << ans.size() << '\n';
  for (int x : ans) cout << x + 1 << ' ';
}