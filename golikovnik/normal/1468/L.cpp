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

i64 modmul64(i64 x, i64 y, i64 p) {
  ui64 q = (long double) x * y / p;
  i64 res = i64(ui64(x) * y - q * p);
  if (res >= p) res -= p;
  if (res < 0) res += p;
  return res;
}

namespace factorization {
  i64 pw(i64 a, i64 n, i64 p) {
    i64 res = 1;
    while (n) {
      if (n & 1) res = modmul64(res, a, p);
      a = modmul64(a, a, p);
      n >>= 1;
    }
    return res;
  }

  bool check_composite(i64 n, int s, i64 d, i64 a) {
    i64 x = pw(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int it = 1; it < s; ++it) {
      x = modmul64(x, x, n);
      if (x == n - 1) return false;
    }
    return true;
  }

  bool is_prime(i64 n) {
    if (n < 4) return n > 1;
    int s = 0;
    i64 d = n - 1;
    while (!(d & 1)) {
      d >>= 1;
      ++s;
    }
    static vector<i64> primes32{2, 7, 61};
    static vector<i64> primes64{2, 325, 9375, 28178, 450775, 9780504,
                                1795265022};
    static i64 const BOUND = i64(4759123141ll);
    for (i64 a : (n <= BOUND ? primes32 : primes64)) {
      if (n == a) return true;
      if (check_composite(n, s, d, a)) return false;
    }
    return true;
  }

  i64 find_divisor(i64 n, int c = 2) {
    auto f = [&](i64 x) {
      auto r = modmul64(x, x, n) + c;
      if (r >= n) r -= n;
      return r;
    };
    i64 x = c;
    i64 g = 1;
    i64 q = 1;
    i64 xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
      y = x;
      for (int i = 1; i < l; ++i) {
        x = f(x);
      }
      int k = 0;
      while (k < l && g == 1) {
        xs = x;
        for (int i = 0; i < m && i < l - k; ++i) {
          x = f(x);
          q = modmul64(q, llabs(y - x), n);
        }
        g = gcd(q, n);
        k += m;
      }
      l *= 2;
    }
    if (g == n) {
      do {
        xs = f(xs);
        g = gcd(llabs(xs - y), n);
      } while (g == 1);
    }
    return g == n ? find_divisor(n, c + 1) : g;
  }

  vector<pair<i64, int>> factorize(i64 m) {
    if (m == 1) {
      return {};
    }
    vector<i64> fac;
    auto rec = [&fac](auto&& rec, i64 m) -> void {
      if (is_prime(m)) {
        fac.push_back(m);
        return;
      }
      auto d = m % 2 == 0 ? 2 : find_divisor(m);
      rec(rec, d);
      rec(rec, m / d);
    };
    rec(rec, m);
    sort(fac.begin(), fac.end());
    vector<pair<i64, int>> ans;
    for (auto x : fac) {
      if (ans.empty() || ans.back().first != x) {
        ans.emplace_back(x, 0);
      }
      ++ans.back().second;
    }
    return ans;
  }
}
using factorization::factorize;
using factorization::is_prime;

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << 0 << '\n';
    return 0;
  }
  vector<i64> a(n);
  map<vector<i64>, vector<int>> byPrimes;
  for (int i = 0; i < n; ++i) {
    auto& x = a[i];
    cin >> x;
    auto f = factorize(x);
    vector<i64> cur;
    for (auto p : f) cur.push_back(p.first);
    byPrimes[cur].push_back(i);
  }
  set<i64> goodPrimes;
  i64 goodSz = 0;
  for (auto& e : byPrimes) {
    auto& vec = e.first;
    if (vec.size() > 1 || e.second.size() < 2) continue;
    goodPrimes.insert(vec[0]);
    goodSz += int(e.second.size());
  }
  for (auto it = byPrimes.begin(); it != byPrimes.end(); ) {
    auto& vec = it->first;
    if (all_of(vec.begin(), vec.end(), [&](auto x) {
      return goodPrimes.count(x);
    })) {
      ++it;
    } else {
      it = byPrimes.erase(it);
    }
  }
  vector<int> ansIds;
  if (k >= goodSz) {
    auto need = k - goodSz;
    for (auto& [pr, ids] : byPrimes) {
      if (pr.size() == 1) {
        ansIds.insert(ansIds.end(), ids.begin(), ids.end());
      } else {
        while (need && !ids.empty()) {
          need--;
          ansIds.push_back(ids.back());
          ids.pop_back();
        }
      }
    }
    if (int(ansIds.size()) != k) {
      ansIds.clear();
    }
  } else {
    vector<vector<int>> singlePrime;
    for (auto p : goodPrimes) singlePrime.push_back(byPrimes[{p}]);
    sort(singlePrime.begin(), singlePrime.end(), [](auto& x, auto& y) {
      return x.size() > y.size();
    });
    assert(singlePrime.back().size() >= 2);
    if (singlePrime[0].size() > 2) {
      for (auto& vec : singlePrime) {
        ansIds.push_back(vec[0]);
        ansIds.push_back(vec[1]);
        for (int i = 2; i < int(vec.size()) && int(ansIds.size()) < k; ++i) {
          ansIds.push_back(vec[i]);
        }
        auto sz = int(ansIds.size());
        if (sz < k) {
          continue;
        }
        if (sz > k) {
          assert(int(ansIds.size()) == k + 1);
          ansIds.erase(ansIds.begin());
        }
        break;
      }
      assert(int(ansIds.size()) == k);
    } else {
      set<i64> neededPrimes;
      if (k % 2 == 1) {
        auto it = min_element(byPrimes.begin(), byPrimes.end(),
                              [](auto& x, auto& y) {
          if (x.first.size() == 1) return false;
          if (y.first.size() == 1) return true;
          return x.first.size() < y.first.size();
        });
        if (it->first.size() == 1) {
          cout << 0 << '\n';
          return 0;
        }
        ansIds.push_back(it->second[0]);
        neededPrimes.insert(it->first.begin(), it->first.end());
      }
      for (auto p : neededPrimes) {
        auto& vec = byPrimes[{p}];
        ansIds.insert(ansIds.end(), vec.begin(), vec.end());
      }
      if (int(ansIds.size()) > k) {
        ansIds.clear();
      } else {
        for (auto p : goodPrimes) {
          if (int(ansIds.size()) == k) break;
          if (neededPrimes.count(p)) continue;
          auto& vec = byPrimes[{p}];
          ansIds.insert(ansIds.end(), vec.begin(), vec.end());
        }
      }
    }
  }
  if (ansIds.empty()) {
    cout << 0 << '\n';
  } else {
    for (auto i : ansIds) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}