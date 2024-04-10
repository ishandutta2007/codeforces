#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  struct seq {
    int k;
    vector<int> a;
    int mn;
    int mx;
    bool ok;

    seq(vector<int> a_) : a(move(a_)) {
      k = (int) a.size();
      mx = 0;
      mn = (int) 1e9;
      ok = false;
      for (int i = 0; i < k; ++i) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        if (i + 1 < k) {
          ok |= a[i] < a[i + 1];
        }
      }
    }
  };
  vector<seq> a;
  int ok = 0;
  int const INF = (int) 1e6 + 20;
  vector<int> mx_cnt(INF);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    vector<int> b(k);
    for (auto& x : b) {
      cin >> x;
    }
    a.emplace_back(b);
    if (a.back().ok) {
      ok++;
    } else {
      mx_cnt[a.back().mx]++;
    }
  }
  auto not_ok = n - ok;
  i64 res = (i64) n * n - (i64) not_ok * not_ok;
  for (int i = INF - 2; i >= 0; --i) {
    mx_cnt[i] += mx_cnt[i + 1];
  }
  for (int i = 0; i < n; ++i) {
    if (a[i].ok) {
      continue;
    }
    res += mx_cnt[a[i].mn + 1];
  }
  cout << res << '\n';
  return 0;
}