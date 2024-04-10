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

  int n, mod;
  cin >> n >> mod;

  auto mul = [&](i64 x, int y, int md) {
    return (int) (x * y % md);
  };
  auto power = [&](int x, i64 y, int md) {
    int r = 1;
    while (y) {
      if (y & 1) {
        r = mul(r, x, md);
      }
      x = mul(x, x, md);
      y >>= 1;
    }
    return r;
  };
  auto phi = [&](int x) {
    int r = x;
    for (int p = 2; p * p <= x; ++p) {
      if (x % p == 0) {
        r /= p;
        r *= p - 1;
        while (x % p == 0) {
          x /= p;
        }
      }
    }
    if (x > 1) {
      r /= x;
      r *= x - 1;
    }
    return r;
  };
  vector<int> mods{mod};
  while (mods.back() > 1) {
    mods.push_back(phi(mods.back()));
  }

  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }

  vector<int> bigs;
  int const BOUND = 32;

  auto my_power = [&](int a, int b) {
    if (b > BOUND) {
      return b;
    }
    if (a > BOUND) {
      return a;
    }
    int r = 1;
    while (b--) {
      r *= a;
      if (r > BOUND) {
        break;
      }
    }
    return r;
  };

  auto eval_big = [&] {
    int cur = 1;
    for (int i = (int) bigs.size() - 1; i >= 0; --i) {
      cur = my_power(bigs[i], cur);
    }
    return cur;
  };

  auto rec = [&](auto&& rec, int l, int r, int i) -> int {
    int md = mods[i];
    if (md == 1) {
      return 0;
    }
    auto base = a[l];
    if (l == r) {
      return base % md;
    }
    if (base == 1) {
      return 1;
    }
    bigs.clear();
    for (int pos = l + 1; pos <= r && a[pos] > 1 && bigs.size() < 4; ++pos) {
      bigs.push_back(a[pos]);
    }
    auto actual = eval_big();
    if (actual <= BOUND) {
      return power(base, actual, md);
    }
    auto deg = rec(rec, l + 1, r, i + 1);
    return power(base, (i64) deg + mods[i + 1], md);
  };

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << rec(rec, l, r, 0) << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}