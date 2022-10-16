//  Copyright 2021 Nikita Golikov

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

int find(string const& s) {
  int occ = 0;
  for (int i = 0; i + 4 <= int(s.size()); ++i) {
    occ += s.substr(i, 4) == "haha";
  }
  return occ;
}

int combine(string const& prefix, string const& suffix) {
  return find(prefix + suffix);
}

void solve(int) {
  static int const NEED_LEN = 3;

  struct data {
    string prefix{};
    string suffix{};
    i64 occ = 0;

    data() = default;

    data(string const& s) {
      occ = find(s);
      int l = min(int(s.size()), NEED_LEN);
      prefix = s.substr(0, l);
      suffix = s.substr(int(s.size() - l), l);
    }

    data operator+(data const& other) const {
      data res;
      res.prefix = prefix;
      if (int(res.prefix.size() < NEED_LEN)) {
        res.prefix += other.prefix;
        res.prefix.resize(min(int(res.prefix.size()), NEED_LEN));
      }
      res.suffix = other.suffix;
      if (int(res.suffix.size() < NEED_LEN)) {
        res.suffix = suffix + other.suffix;
        int nlen = min(NEED_LEN, int(res.suffix.size()));
        res.suffix = res.suffix.substr(int(res.suffix.size()) - nlen, nlen);
      }
      res.occ = occ + other.occ + combine(suffix, other.prefix);
      return res;
    }
  };

  map<string, data> mp;
  int q;
  cin >> q;
  string lastSet;
  while (q--) {
    string s1;
    cin >> s1;
    string op;
    cin >> op;
    if (op == ":=") {
      string s2;
      cin >> s2;
      mp[s1] = data(s2);
      lastSet = s1;
    } else {
      string x, y;
      cin >> x >> op >> y;
      mp[s1] = mp[x] + mp[y];
      lastSet = s1;
    }
  }
  cout << mp[lastSet].occ << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}