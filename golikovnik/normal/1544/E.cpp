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

void solve(int) {
  string s;
  cin >> s;
  int n = int(s.size());
  map<char, int> cnt;
  for (char ch : s) ++cnt[ch];
  if (cnt.size() == 1) {
    cout << s << '\n';
    return;
  }
  {
    bool ok = false;
    char who;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      if (cnt[ch] == 1) {
        ok = true;
        who = ch;
        break;
      }
    }
    if (ok) {
      cout << who;
      s.erase(find(s.begin(), s.end(), who));
      sort(s.begin(), s.end());
      cout << s << '\n';
      return;
    }
  }
  char ch;
  for (ch = 'a'; ; ++ch) {
    if (cnt[ch]) break;
  }
  string res;
  if (cnt[ch] - 2 <= (n - 3 + 1) / 2) {
    char other;
    for (other = ch + 1; ; ++other) {
      if (cnt[other]) break;
    }
    res += ch;
    res += ch;
    res += other;
    cnt[ch] -= 2;
    cnt[other] -= 1;
    auto putAny = [&] {
      for (char cc = 'a'; cc <= 'z'; ++cc) {
        if (cnt[cc] && (cc != ch || res.back() != cc)) {
          res += cc;
          --cnt[cc];
          return;
        }
      }
      assert(false);
    };
    for (int it = 0; it < n - 3; ++it) {
      putAny();
    }
  } else {
    char other;
    for (other = ch + 1; ; ++other) {
      if (cnt[other]) break;
    }
    res += ch;
    res += other;
    cnt[ch]--;
    cnt[other]--;
    int nz = 0;
    for (char cc = 'a'; cc <= 'z'; ++cc) nz += bool(cnt[cc]);
    if (nz == 2) {
      for (int it = 0; it < cnt[other]; ++it) res += other;
      for (int it = 0; it < cnt[ch]; ++it) res += ch;
    } else {
      for (int it = 0; it < cnt[ch]; ++it) res += ch;
      cnt[ch] = 0;
      char who3;
      for (who3 = other + 1; ; ++who3) if (cnt[who3]) break;
      res += who3;
      --cnt[who3];
      for (char cc = 'a'; cc <= 'z'; ++cc) res += string(cnt[cc], cc);
    }
  }
  cout << res << '\n';
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