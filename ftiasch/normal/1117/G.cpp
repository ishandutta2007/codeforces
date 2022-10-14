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

struct Query {
  void reverse(int n) {
    l = n - 1 - l;
    r = n - 1 - r;
    std::swap(l, r);
  }

  int l, r, id;
  Long result;
};

bool operator<(const Query &p, const Query &q) { return p.r < q.r; }

std::ostream &operator<<(std::ostream &out, const Query &q) {
  return out << KV(q.l) << KV(q.r) << KV(q.id) << KV(q.result);
}

const int N = 1'000'000;

int n, m, a[N];
Long f0[N], f1[N];
Query q[N];

template <int d> void add(int i) {
  for (int k = i; ~k; k -= ~k & k + 1) {
    f0[k] += d * (n - i);
  }
  for (int k = i; k < n; k += ~k & k + 1) {
    f1[k] += d;
  }
}

Long query(int i) {
  Long result = 0;
  for (int k = i - 1; ~k; k -= ~k & k + 1) {
    result += f1[k];
  }
  result *= (n - i);
  for (int k = i; k < n; k += ~k & k + 1) {
    result += f0[k];
  }
  return result;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0, l; i < m; ++i) {
    scanf("%d", &l);
    q[i].l = l - 1;
  }
  for (int i = 0, r; i < m; ++i) {
    scanf("%d", &r);
    q[i].r = r - 1;
    q[i].id = i;
    q[i].result = r - q[i].l;
  }
  for (int _ = 0; _ < 2; ++_) {
    std::sort(q, q + m);

    // std::cout << std::vector<Query>(q, q + m) << std::endl;

    memset(f0, 0, sizeof(*f0) * n);
    memset(f1, 0, sizeof(*f1) * n);

    std::vector<int> stack;
    for (int i = 0, j = 0; i < n; ++i) {
      while (!stack.empty() && a[stack.back()] < a[i]) {
        stack.pop_back();
      }
      int st = stack.empty() ? 0 : stack.back() + 1;
      add<1>(st);
      add<-1>(i);
      stack.push_back(i);

      while (j < m && q[j].r == i) {
        q[j].result += query(q[j].l);
        j++;
      }
    }

    std::reverse(a, a + n);
    for (int i = 0; i < m; ++i) {
      q[i].reverse(n);
    }
  }
  std::sort(q, q + m,
            [&](const Query &p, const Query &q) { return p.id < q.id; });
  for (int i = 0; i < m; ++i) {
    printf("%lld%c", q[i].result, " \n"[i + 1 == m]);
  }
}