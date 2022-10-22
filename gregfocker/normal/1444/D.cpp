#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 7;
bool ok[N * N];
int last[N * N];

vector<int> get(int n, int sum, int a[]) {
  for (int i = 0; i <= sum; i++) {
    last[i] = 0;
    ok[i] = 0;
  }
  ok[0] = 1;
  int cur = 0;
  for (int j = 1; j <= n; j++) {
    int x = a[j];
    for (int i = min(sum - x, cur); i >= 0; i--) {
      if (ok[i] && !ok[i + x]) {
        ok[i + x] = 1;
        last[i + x] = j;
      }
    }
    cur += x;
  }
  if (ok[sum] == 0) {
    return {};
  }
  vector<int> ret;
  while (sum) {
    ret.push_back(last[sum]);
    sum -= a[last[sum]];
  }
  return ret;
}

int n;
int a[N];
int b[N];
bool inside[N];

vector<int> complement(vector<int> a) {
  for (int i = 1; i <= n; i++) {
    inside[i] = 0;
  }
  for (auto &i : a) {
    inside[i] = 1;
  }
  a.clear();
  for (int i = 1; i <= n; i++) {
    if (inside[i] == 0) {
      a.push_back(i);
    }
  }
  return a;
}

bool cmp(pair<int, int> f, pair<int, int> s) {
  ll fx = f.first, fy = f.second;
  ll sx = s.first, sy = s.second;
  return fx * sy < fy * sx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int h, v;
    cin >> h;
    for (int i = 1; i <= h; i++) {
      cin >> a[i];
    }
    cin >> v;
    for (int i = 1; i <= v; i++) {
      cin >> b[i];
    }
    if (h != v) {
      cout << "No\n";
      continue;
    }
    n = h;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int sum_a = 0, sum_b = 0;
    for (int i = 1; i <= n; i++) {
      sum_a += a[i];
      sum_b += b[i];
    }
    if (sum_a % 2 == 1 || sum_b % 2 == 1) {
      cout << "No\n";
      continue;
    }
    vector<int> r = get(n, sum_a / 2, a), l;
    vector<int> d = get(n, sum_b / 2, b), u;
    if (r.empty() || d.empty()) {
      cout << "No\n";
      continue;
    }
    l = complement(r);
    u = complement(d);
    if ((int) r.size() > (int) l.size()) {
      swap(r, l);
    }
    if ((int) d.size() > (int) u.size()) {
      swap(d, u);
    }
    vector<pair<int, int>> ru;
    vector<pair<int, int>> lu;
    vector<pair<int, int>> ld;
    for (auto &i : r) {
      ru.push_back({a[i], b[u.back()]});
      u.pop_back();
    }
    for (auto &i : l) {
      if (!u.empty()) {
        lu.push_back({a[i], b[u.back()]});
        u.pop_back();
      } else {
        ld.push_back({a[i], b[d.back()]});
        d.pop_back();
      }
    }
    sort(ru.begin(), ru.end(), cmp);
    sort(ld.begin(), ld.end(), cmp);


    /// ru, ld
    cout << "Yes\n";
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
      cout << x << " " << y << "\n";
      if (!ru.empty()) {
        x -= ru.back().first;
        cout << x << " " << y << "\n";
        y -= ru.back().second;
        ru.pop_back();
        continue;
      }
      if (!lu.empty()) {
        x += lu.back().first;
        cout << x << " " << y << "\n";
        y -= lu.back().second;
        lu.pop_back();
        continue;
      }
      if (!ld.empty()) {
        x += ld.back().first;
        cout << x << " " << y << "\n";
        y += ld.back().second;
        ld.pop_back();
        continue;
      }
      assert(0);
    }
    assert(x == 0 && y == 0);
  }
}
/**

**/