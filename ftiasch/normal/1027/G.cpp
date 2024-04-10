#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>

namespace {

template <typename Tuple, size_t... Index>
std::ostream &serialize_tuple(std::ostream &out, const Tuple &t,
                              std::index_sequence<Index...>) {
  out << "(";
  (..., (out << (Index == 0 ? "" : ", ") << std::get<Index>(t)));
  return out << ")";
}

} // namespace

template <typename A, typename B>
std::ostream &operator<<(std::ostream &out, const std::pair<A, B> &v) {
  return out << "(" << v.first << ", " << v.second << ")";
}

template <typename... T>
std::ostream &operator<<(std::ostream &out, const std::tuple<T...> &t) {
  return serialize_tuple(out, t, std::make_index_sequence<sizeof...(T)>());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &out, const std::array<T, N> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::list<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename K>
std::ostream &operator<<(std::ostream &out, const std::set<K> &s) {
  out << "{";
  bool first = true;
  for (auto &&k : s) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k;
  }
  return out << "}";
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &m) {
  out << "{";
  bool first = true;
  for (auto &&[k, v] : m) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k << ": " << v;
  }
  return out << "}";
}

#define KV(x) #x << "=" << x << ";"
#line 2 "/home/ftiasch/Documents/shoka/sieve.h"

struct PrimeGen : public std::vector<int> {
  PrimeGen(int m) : std::vector<int>(), min_div_(m, -1) {
    for (int d = 2; d < m; ++d) {
      if (min_div_[d] == -1) {
        min_div_[d] = d;
        push_back(d);
      }
      for (int p : *this) {
        if (d * p >= m) {
          break;
        }
        min_div_[p * d] = p;
        if (d % p == 0) {
          break;
        }
      }
    }
  }

  int min_div(int n) const { return min_div_[n]; }

private:
  std::vector<int> min_div_;
};
#line 3 "sol.cpp"

#include <bits/stdc++.h>

using Long = long long;

const int B = 1e7;

PrimeGen primes(B);

using Factorization = std::vector<std::pair<Long, int>>;

Factorization factor(Long n) {
  Factorization result;
  for (Long p = 2; p * p <= n && n >= B; ++p) {
    if (n % p == 0) {
      int e = 0;
      while (n % p == 0) {
        n /= p;
        e++;
      }
      result.emplace_back(p, e);
    }
  }
  if (n >= B) {
    result.emplace_back(n, 1);
  } else {
    while (n > 1) {
      Long p = primes.min_div(n);
      int e = 0;
      while (n % p == 0) {
        n /= p;
        e++;
      }
      result.emplace_back(p, e);
    }
  }
  return result;
}

Factorization merge(const Factorization &a, const Factorization &b) {
  Factorization result;
  for (size_t i = 0, j = 0; i < a.size() || j < b.size();) {
    if (i < a.size() && j < b.size() && a[i].first == b[j].first) {
      result.emplace_back(a[i].first, a[i].second + b[j].second);
      i++;
      j++;
    } else if (i < a.size() && (j == b.size() || a[i].first < b[j].first)) {
      result.emplace_back(a[i++]);
    } else {
      result.emplace_back(b[j++]);
    }
  }
  return result;
}

Long safe_mul(Long a, Long b, Long m) {
  return static_cast<Long>(static_cast<__int128>(a) * static_cast<__int128>(b) %
                           static_cast<__int128>(m));
}

Long safe_pow(Long a, Long n, Long m) {
  Long result = 1;
  while (n) {
    if (n & 1) {
      result = safe_mul(result, a, m);
    }
    a = safe_mul(a, a, m);
    n >>= 1;
  }
  return result;
}

struct Solver {
  Solver(Long m, Long x) : x(x), fm(factor(m)) {
    for (auto [p, _] : fm) {
      fpdivs.push_back(factor(p - 1));
    }
  }

  Long recur(size_t i, Long d, Long phi_d, Factorization fphi) {
    if (i < fm.size()) {
      Long result = recur(i + 1, d, phi_d, fphi);
      auto [p, maxe] = fm[i];
      d *= p;
      phi_d *= (p - 1);
      fphi = merge(fphi, fpdivs[i]);
      result += recur(i + 1, d, phi_d, fphi);
      for (int e = 2; e <= maxe; ++e) {
        d *= p;
        phi_d *= p;
        fphi = merge(fphi, {{p, 1}});
        result += recur(i + 1, d, phi_d, fphi);
      }
      return result;
    } else {
      // result = phi_d / ord(x % d)
      Long xx = x % d;
      Long ord = phi_d;
      for (auto [p, _] : fphi) {
        while (ord % p == 0 && safe_pow(xx, ord / p, d) == 1) {
          ord /= p;
        }
      }
      return phi_d / ord;
    }
  }

  Long x;
  Factorization fm;
  std::vector<Factorization> fpdivs;
};

int main() {
  Long m, x;
  std::cin >> m >> x;
  Solver solver{m, x};
  printf("%lld\n", solver.recur(0, 1, 1, {}));
}