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

int main() {
  int q;
  scanf("%d", &q);
  int cnt_dbl = 0;
  long long sum = 0, sum_top = 0;
  std::map<int, int> bot, top;
  std::set<int> top_dbl;
  auto answer = [&]() -> long long {
    int cnt_dbl_top = top_dbl.size();
    if (cnt_dbl_top < cnt_dbl) {
      return sum + sum_top;
    }
    if (cnt_dbl == 0) {
      return sum;
    }
    return sum + sum_top - *top_dbl.begin() +
           (bot.empty() ? 0 : bot.rbegin()->first);
    // cnt_dbl_top == cnt_dbl >= 1
  };
  while (q--) {
    int tp, d;
    scanf("%d%d", &tp, &d);
    if (tp == 1) {
      if (d > 0) {
        cnt_dbl++;
      } else {
        cnt_dbl--;
      }
    }
    if (d > 0) {
      sum += d;
      if (top.empty() || d < top.begin()->first) {
        bot.emplace(d, tp);
      } else {
        sum_top += d;
        top.emplace(d, tp);
        if (tp == 1) {
          top_dbl.insert(d);
        }
      }
    } else {
      sum += d;
      auto it = bot.find(-d);
      if (it == bot.end()) {
        sum_top += d;
        top.erase(-d);
        if (tp == 1) {
          top_dbl.erase(-d);
        }
      } else {
        bot.erase(it);
      }
    }
    while (top.size() > cnt_dbl) {
      auto it = top.begin();
      sum_top -= it->first;
      bot.insert(*it);
      if (it->second) {
        top_dbl.erase(it->first);
      }
      top.erase(it);
    }
    while (top.size() < cnt_dbl) {
      auto it = std::prev(bot.end());
      sum_top += it->first;
      top.insert(*it);
      if (it->second) {
        top_dbl.insert(it->first);
      }
      bot.erase(it);
    }
    // std::cout << KV(cnt_dbl) << KV(sum) << KV(top) << KV(sum_top) << KV(bot)
    // << KV(top_dbl) << std::endl;
    printf("%lld\n", answer());
  }
}