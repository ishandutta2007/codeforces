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

template <class MOD>
struct modular {
  int val{};

  constexpr static int mod() {
    return MOD::value;
  }

  constexpr static int norm(i64 x) {
    int res = -mod() <= x && x < mod() ? x : int(x % mod());
    if (res < 0) {
      res += mod();
    }
    return res;
  }

  constexpr modular(i64 x = 0) : val(norm(x)) {}

  explicit operator int() const {
    return val;
  }

  explicit operator i64() const {
    return val;
  }

  modular& operator+=(modular other) {
    val += other.val;
    if (val >= mod()) {
      val -= mod();
    }
    return *this;
  }

  friend modular operator+(modular x, modular y) {
    return x += y;
  }

  modular& operator-=(modular other) {
    val -= other.val;
    if (val < 0) {
      val += mod();
    }
    return *this;
  }

  friend modular operator-(modular x, modular y) {
    return x -= y;
  }

  modular& operator++() {
    if (++val == mod()) {
      val = 0;
    }
    return *this;
  }

  modular& operator--() {
    if (--val < 0) {
      val = mod() - 1;
    }
    return *this;
  }

  friend modular operator*(modular x, modular y) {
    return modular{(i64) x.val * y.val};
  }

  modular operator*=(modular other) {
    return *this = *this * other;
  }

  friend bool operator<(modular x, modular y) {
    return int(x) < int(y);
  }

  friend bool operator==(modular x, modular y) {
    return int(x) == int(y);
  }

  friend bool operator!=(modular x, modular y) {
    return int(x) != int(y);
  }

  modular operator-() const {
    return 0 - *this;
  }

  friend istream& operator>>(istream& in, modular& x) {
    i64 t;
    in >> t;
    x.val = norm(t);
    return in;
  }

  friend ostream& operator<<(ostream& out, modular x) {
    return out << x.val;
  }

  explicit operator bool() const {
    return bool(val);
  }

  modular power(i64 deg) const {
    auto x = *this;
    if (!x) {
      return !deg;
    }
    deg %= modular<MOD>::mod() - 1;
    if (deg < 0) {
      deg += modular<MOD>::mod() - 1;
    }
    modular<MOD> res = 1;
    while (deg) {
      if (deg & 1) {
        res *= x;
      }
      x *= x;
      deg /= 2;
    }
    return res;
  }

  modular inv() const {
    return power(-1);
  }

  modular operator/(modular y) const {
    return (*this) * y.inv();
  }

  modular& operator/=(modular other) {
    return *this = *this / other;
  }
};

struct DynamicMod {
  static int value;
};
int DynamicMod::value;

using m1 = modular<integral_constant<int, int(1e9 + 7)>>;
using m2 = modular<integral_constant<int, int(1e9 + 9)>>;

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

template <class T1, class T2, int first = 'a'>
struct _hash_t {
  T1 x;
  T2 y;

  _hash_t() : x(0), y(0) {}
  _hash_t(T1 x_, T2 y_) : x(x_), y(y_) {}
  _hash_t(int ch) : x(ch - first + 1), y(ch - first + 1) {}

  _hash_t operator+(_hash_t const& other) const {
    return {x + other.x, y + other.y};
  }

  _hash_t operator-(_hash_t const& other) const {
    return {x - other.x, y - other.y};
  }

  _hash_t operator*(_hash_t const& other) const {
    return {x * other.x, y * other.y};
  }

  friend bool operator==(_hash_t a, _hash_t b) {
    return a.x == b.x && a.y == b.y;
  }

  friend bool operator!=(_hash_t a, _hash_t b) {
    return !(a == b);
  }
};

using hash_t = _hash_t<m1, m2>;
vector<hash_t> powers;

hash_t getHashPower(int len) {
  if (powers.empty()) {
    powers.emplace_back(1, 1);
    powers.emplace_back(rnd(1, int(1e9)), rnd(1, int(1e9)));
  }
  while (int(powers.size()) <= len) {
    powers.push_back(powers.back() * powers[1]);
  }
  return powers[len];
}

hash_t concat(hash_t x, hash_t y, int ylen) {
  return x * getHashPower(ylen) + y;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  powers.reserve(max(n, k) + 1);

  string s;
  cin >> s;
  vector<hash_t> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = concat(pref[i], s[i], 1);
  }

  vector<vector<hash_t>> repeatPowers(n + 1);
  for (int l = 1; l <= n; ++l) {
    hash_t cur{};
    int len = 0;
    repeatPowers[l].reserve((k + l - 1) / l);
    while (len <= k) {
      repeatPowers[l].push_back(cur);
      cur = concat(cur, pref[l], l);
      len += l;
    }
  }
  auto getHash = [&](int len, int need) {
    int repeat = need / len;
    auto result = repeatPowers[len][repeat];
    return concat(result, pref[need % len], need % len);
  };
  auto isLess = [&](int a, int b) {
    int left = 0;
    int right = k + 1;
    while (left + 1 != right) {
      int middle = (left + right) / 2;
      if (getHash(a, middle) != getHash(b, middle)) {
        right = middle;
      } else {
        left = middle;
      }
    }
    if (left == k) return false;
    return s[left % a] < s[left % b];
  };

  int opt = 1;
  for (int len = 2; len <= n; ++len) {
    if (isLess(len, opt)) {
      opt = len;
    }
  }
  string res;
  for (int i = 0; i < k; ++i) {
    res += s[i % opt];
  }
  cout << res << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}