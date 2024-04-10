#include <bits/stdc++.h>

using namespace std;

vector<int> build_sa(string s) {
  s += '\0';
  int n = (int) s.size();
  vector<int> p(n), c(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return s[i] < s[j];
  });
  auto norm = [n](int x) {
    return x < 0 ? x + n : x >= n ? x - n : x;
  };
  for (int i = 1; i < n; ++i) c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  for (int k = 1; k < n; k *= 2) {
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) ++cnt[c[i] + 1];
    for (int i = 0; i < n; ++i) cnt[i + 1] += cnt[i];
    vector<int> pp(n);
    for (int i = 0; i < n; ++i) {
      auto j = norm(p[i] - k);
      pp[cnt[c[j]]++] = j;
    }
    vector<int> cc(n);
    for (int i = 1; i < n; ++i) {
      pair x{c[pp[i - 1]], c[norm(pp[i - 1] + k)]};
      pair y{c[pp[i]], c[norm(pp[i] + k)]};
      cc[pp[i]] = cc[pp[i - 1]] + (x != y);
    }
    p = move(pp), c = move(cc);
  }
  p.erase(p.begin());
  return p;
}

using i64 = int64_t;
using ui64 = uint64_t;

i64 solve(string t, vector<string> a) {
  auto sa = build_sa(t);
  auto rt = t;
  reverse(rt.begin(), rt.end());
  auto rsa = build_sa(rt);

  auto find = [](string const& s, string const& t, auto const& sa) {
    int n = (int) s.size();
    int m = (int) t.size();

    int left = -1;  //  le
    int right = m;  //  geq
    while (left + 1 != right) {
      int middle = (left + right) / 2;
      int start = sa[middle];

      bool less = false;
      for (int j = start; j < start + n; ++j) {
        if (t[j] > s[j - start]) break;
        if (t[j] < s[j - start]) {
          less = true;
          break;
        }
      }
      if (less) {
        left = middle;
      } else {
        right = middle;
      }
    }
    int first_geq = right;
    left = -1; // leq
    right = m; // gr
    while (left + 1 != right) {
      int middle = (left + right) / 2;
      int start = sa[middle];

      bool gr = false;
      for (int j = start; j < start + n; ++j) {
        if (t[j] < s[j - start]) break;
        if (t[j] > s[j - start]) {
          gr = true;
          break;
        }
      }
      if (gr) {
        right = middle;
      } else {
        left = middle;
      }
    }
    return make_pair(first_geq, right);
  };

  int n = (int) a.size();
  int m = (int) t.size();
  vector<i64> add(m + 1), radd(m + 1);
  for (int i = 0; i < n; ++i) {
    auto& s = a[i];
    auto[l, r] = find(s, t, sa);
    add[l]++, add[r]--;
    reverse(s.begin(), s.end());
    tie(l, r) = find(s, rt, rsa);
    radd[l]++, radd[r]--;
  }
  for (int i = 0; i < m; ++i) {
    add[i + 1] += add[i];
    radd[i + 1] += radd[i];
  }
  vector<i64> suff(m), pref(m);
  for (int i = 0; i < m; ++i) {
    suff[sa[i]] = add[i];
    pref[m - rsa[i] - 1] = radd[i];
  }
  i64 ans = 0;
  for (int i = 0; i + 1 < m; ++i) {
    ans += pref[i] * suff[i + 1];
  }
  return ans;
}

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string t;
  cin >> t;
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& s : a) cin >> s;
  cout << solve(t, a) << '\n';
  return 0;
}