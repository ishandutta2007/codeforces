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
 	
typedef long long ll;

using namespace std;	

const int N = 2e5 + 7;

int t[4 * N];
int mod[4 * N];

void update(int v, int x) {
  t[v] += x;
  mod[v] += x;
}

void push(int v) {
  if (mod[v]) {
    update(2 * v + 1, mod[v]);
    update(2 * v + 2, mod[v]);
    mod[v] = 0;
  }
}

void modify(int ql, int qr, int x, int l, int r, int v) {
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) {
    update(v, x);
  } else {
    push(v);
    int m = (l + r) >> 1;
    modify(ql, qr, x, l, m, 2 * v + 1);
    modify(ql, qr, x, m + 1, r, 2 * v + 2);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  }
}

int get(int ql, int qr, int l, int r, int v) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) return t[v];
  push(v);
  int m = (l + r) >> 1;
  return max(get(ql, qr, l, m, 2 * v + 1), get(ql, qr, m + 1, r, 2 * v + 2));
}

int main() {	
  ios_base::sync_with_stdio(false); cin.tie(0);	
#ifdef LOCAL	
  freopen("input.txt", "r", stdin);	
#endif	
  int d, n, m;
  cin >> d >> n >> m;
  vector <pair <int, int>> a(m + 1);
  for (int i = 0; i < m; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  a[m] = {d, 0};
  sort(a.begin(), a.end()); 
  ll ans = 0; int have = n;
  set <pair <int, int>> gs;
  for (int i = 0; i < (int)a.size(); ++i) {
    int dst = a[i].first - (i == 0 ? 0 : a[i - 1].first);
    if (have >= dst) {
      have -= dst;
    } else {
      int need = dst - have;
      have -= dst;
      while (need) {
        if (gs.empty()) {
          cout << "-1\n";
          return 0;
        }
        auto p = *gs.begin();
        gs.erase(gs.begin());
        int id = p.second;
        int can = n - get(id, i - 1, 0, m, 0);
        int tk = min(need, can);
        have += tk;
        need -= tk;
        can -= tk;
        ans += (ll)tk * p.first;
        modify(id, i - 1, tk, 0, m, 0);
        if (can > 0) {
          gs.insert(p);
        }
      }
    }
    modify(i, i, have, 0, m, 0);
    gs.insert({a[i].second, i});
  }
  cout << ans << '\n';
}