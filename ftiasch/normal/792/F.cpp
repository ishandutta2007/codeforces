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
#line 2 "sol.cpp"

#include <bits/stdc++.h>

using Long = long long;

struct Line {
  int k, b;
};

std::ostream &operator<<(std::ostream &out, const Line &l) {
  return out << "y=" << l.k << "*x+" << l.b;
}

bool operator<(const Line &u, const Line &v) { return u.k < v.k; }

Long infinity(int d) {
  using Limit = std::numeric_limits<Long>;
  return d ? (d > 0 ? Limit::max() : Limit::min()) : 0;
}

bool check3(const Line &u, const Line &v, const Line &w) {
  // u.b - v.b = (v.k - u.k) * x
  return 1LL * (u.b - v.b) * (w.k - v.k) <
         (u.k == INT_MIN ? infinity(v.b - w.b)
                         : 1LL * (v.b - w.b) * (v.k - u.k));
}

struct ConvexHull : public std::set<Line> {
  ConvexHull() : std::set<Line>{Line{INT_MIN, 0}, Line{0, 0}} {}

  void add_line(const Line &l) {
    // std::cerr << "add " << KV(l) << std::endl;
    auto iterator = lower_bound(l);
    if (l.k == iterator->k) {
      if (l.b <= iterator->b) {
        return;
      }
      erase(iterator);
      iterator = lower_bound(l);
    }
    if (!check3(*std::prev(iterator), l, *iterator)) {
      return;
    }
    auto bwd = std::prev(iterator);
    auto fwd = iterator;
    while (std::next(fwd) != end() && !check3(l, *fwd, *std::next(fwd))) {
      auto backup = fwd;
      fwd++;
      erase(backup);
    }
    while (bwd != begin() && !check3(*std::prev(bwd), *bwd, l)) {
      auto backup = bwd;
      bwd--;
      erase(backup);
    }
    insert(l);
  }
};

int main() {
  int Q;
  long long M;
  scanf("%d%lld", &Q, &M);
  int lastq = 0;
  ConvexHull hull;
  for (int q = 1; q <= Q; ++q) {
    int op, a_, b_;
    scanf("%d%d%d", &op, &a_, &b_);
    a_ = (a_ + lastq) % 1'000'000 + 1;
    b_ = (b_ + lastq) % 1'000'000 + 1;
    // std::cerr << KV(op) << KV(a_) << KV(b_) << std::endl;
    if (op == 1) {
      int dama = a_;
      int mana = b_;
      hull.add_line(Line{-mana, dama});
      // std::cerr << KV(hull) << std::endl;
    } else {
      int T = a_;
      int H = b_;
      // Primal:
      // sum_i mana[i] * t[i] <= M
      // sum_i       1 * t[i] <= T
      // max   dama[i] * t[i]
      // ---
      // Dual:
      // mana[i] * X + Y >= dama[i] => Y >= dama[i] - mana[i] * X
      // {min   M * X + T * Y = T * (M/T * X + 1 * Y)} >= H
      Long limit = -M / T;
      // std::cerr << KV(limit) << std::endl;
      auto iterator = hull.lower_bound(
          Line{static_cast<int>(std::max(limit, -1'000'000LL)), 0});
      Line u = *std::prev(iterator);
      Line v = *iterator;
      bool result;
      if (u.k == INT_MIN) {
        // std::cerr << "Case 1" << std::endl;
        // x = 0
        // y = v.b
        result = 1LL * T * v.b >= H;
      } else {
        // std::cerr << "Case 2;" << KV(u) << KV(v) << std::endl;
        // y = u.k * x + u.b
        // y = v.k * x + v.b
        // (v.k - u.k) * x + (v.b - u.b) = 0
        // x = (u.b - v.b) / (v.k - u.k)
        // y = (u.b * u.k - v.b * u.k) / (v.k - u.k) + u.b
        //   = (u.b * v.k - v.b * u.k) / (v.k - u.k)
        result = 1LL * M * (u.b - v.b) +
                     1LL * T * (1LL * u.b * v.k - 1LL * v.b * u.k) >=
                 1LL * H * (v.k - u.k);
      }
      puts(result ? "YES" : "NO");
      if (result) {
        lastq = q;
      }
    }
  }
}