//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  string s, t;
  cin >> s >> t;

  auto apply = [&](vector<int> const& a, vector<int> const& b) {
    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
      c[i] = b[a[i]];
    }
    return c;
  };
  auto permute = [&](string const& str, vector<int> const& p) {
    auto rs = str;
    for (int i = 0; i < k; ++i) {
      rs[i] = str[p[i]];
    }
    return rs;
  };
  auto to_int = [&](string const& msk) {
    int ans = 0;
    for (char ch : msk) {
      ans *= 2;
      ans += ch - '0';
    }
    return ans;
  };
  vector<int> p(k);
  iota(p.begin(), p.end(), 0);
  vector<int> left(1 << k, n + 1), right(1 << k, -1);
  auto updL = [&](int i) {
    smin(left[to_int(permute(s, p))], i);
  };
  auto updR = [&](int i) {
    smax(right[to_int(permute(t, p))], i);
  };
  updL(0);

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    vector<int> tmp(k);
    iota(tmp.begin(), tmp.end(), 0);
    swap(tmp[a], tmp[b]);
    p = apply(p, tmp);
    if (i + 1 != n) {
      updL(i + 1);
    }
    updR(i + 1);
  }
  for (int b = 0; b < k; ++b) {
    for (int i = (1 << k) - 1; i >= 0; --i) {
      if (!(i >> b & 1)) {
        smin(left[i], left[i ^ (1 << b)]);
        smax(right[i], right[i ^ (1 << b)]);
      }
    }
  }
  int init = 0;
  for (int i = 0; i < k; ++i) {
    if (s[i] == t[i]) {
      ++init;
      if (s[i] == '1') {
        init -= 2;
      }
    }
  }

  int ans = -1;
  int ansL = -1;
  int ansR = -1;
  for (int mask = 0; mask < (1 << k); ++mask) {
    auto cnt = __builtin_popcount(mask);
    auto new_ans = init + 2 * cnt;
    if (new_ans > ans && right[mask] - left[mask] >= m) {
      ans = new_ans;
      ansL = left[mask] + 1;
      ansR = right[mask];
    }
  }
  cout << ans << '\n' << ansL << ' ' << ansR << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}