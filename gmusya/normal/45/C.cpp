#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <set>

using namespace std;

mt19937 gen(time(0));

const int INF = 1e9;


struct fenwick {
  int n;
  vector <int> t;
  fenwick(int _n) {
    n = 1;
    while (n < _n)
      n = (n << 1);
    t.resize(n);
  }
  void add(int x, int val) {
    for (int i = x; i < n; i |= i + 1)
      t[i] += val;
  }
  int get(int x) {
    int res = 0;
    for (int i = x; i != -1; i = (i & (i + 1)) - 1)
      res += t[i];
    return res;
  }
  int kth_zero(int k) {
    int l = 0, r = n - 1;
    while (l != r) {
      int m = (l + r) / 2;
      if (t[m] < k)
        k -= t[m], l = m + 1;
      else
        r = m;
    }
    if (k != 1) return n;
    return l;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <char> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  fenwick fe(n);
  for (int i = 0; i < n; i++)
    fe.add(i, 1);
  set <pair <int, pair <int, int>>> s;
  for (int i = 0; i + 1 < n; i++)
    if (c[i] != c[i + 1])
      s.insert({abs(a[i] - a[i + 1]), {i, i + 1}});
  vector <bool> used(n);
  vector <pair <int, int>> ans;
  while (!s.empty()) {
    auto now = *s.begin();
    s.erase(now);
    int l = now.second.first, r = now.second.second;
    if (used[l] || used[r])
      continue;
    ans.push_back({l + 1, r + 1});
    used[l] = true;
    used[r] = true;
    int posl = fe.kth_zero(fe.get(l) - 1);
    int posr = fe.kth_zero(fe.get(r) + 1);
    if (posl >= n || posr >= n || used[posl] || used[posr])
      continue;
    fe.add(l, -1);
    fe.add(r, -1);
    if (c[posr] != c[posl])
      s.insert({abs(a[posr] - a[posl]), {posl, posr}});
  }
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now.first << ' ' << now.second << '\n';
  return 0;
}