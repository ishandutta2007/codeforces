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

const int MAX_LIMIT = 300;

int main() {
  int n;
  scanf("%d", &n);
  int speed;
  std::vector<int> overtakes, speed_limits;
  for (int i = 0; i < n; ++i) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &speed);
      speed_limits.push_back(-speed);
    } else if (type == 2) {
      overtakes.push_back(-1);
    } else if (type == 3) {
      int limit;
      scanf("%d", &limit);
      speed_limits.push_back(limit);
      speed_limits.push_back(-speed);
    } else if (type == 4) {
      overtakes.push_back(0);
    } else if (type == 5) {
      speed_limits.push_back(MAX_LIMIT);
      speed_limits.push_back(-speed);
    } else {
      overtakes.push_back(1);
    }
  }

  int result = 0;
  {
    bool has_overtakes = false;
    for (int i = overtakes.size(); i--;) {
      int overtake = overtakes[i];
      if (overtake == -1) {
        has_overtakes = true;
      } else if (overtake == 0) {
        has_overtakes = false;
      } else if (has_overtakes) {
        result++;
      }
    }
  }
  // std::cout << KV(result) << KV(speed_limits) << std::endl;
  {
    int max_speed = 0;
    for (int i = speed_limits.size(); i--;) {
      if (speed_limits[i] < 0) {
        int speed = -speed_limits[i];
        max_speed = std::max(max_speed, speed);
      } else {
        int limit = speed_limits[i];
        if (max_speed <= limit) {
          max_speed = 0;
        } else {
          result++;
        }
      }
      // std::cout << KV(speed) << KV(limit) << KV(max_speed) << std::endl;
    }
  }
  // std::cout << KV(result) << std::endl;
  printf("%d\n", result);
}