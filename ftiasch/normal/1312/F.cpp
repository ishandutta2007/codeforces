#line 1 "sol.cpp"
#include <bits/stdc++.h>

int mex(const std::vector<int> &v) {
  int i = 0;
  while (std::find(v.begin(), v.end(), i) != v.end()) {
    i++;
  }
  return i;
}

const int N = 5;

using State = std::array<std::array<int, 3>, N>;

struct Sg {
  Sg(int x, int y, int z) {
    State s;
    for (int i = 0; i < N; ++i) {
      s[i][0] = s[i][1] = s[i][2] = 0;
    }
    std::map<State, int> states;
    for (int i = 0;; ++i) {
      auto iterator = states.find(s);
      if (iterator != states.end()) {
        offset = iterator->second;
        period = i - offset;
        break;
      }
      states.emplace(s, i);
      values.push_back(s[N - 1]);
      std::array<int, 3> nv{
          mex({s[N - x][0], s[N - y][1], s[N - z][2]}),
          mex({s[N - x][0], s[N - z][2]}),
          mex({s[N - x][0], s[N - y][1]}),
      };
      for (int j = 1; j < N; ++j) {
        s[j - 1] = s[j];
      }
      s[N - 1] = nv;
    }
  }

  const std::array<int, 3> &operator[](long long i) const {
    return values[i < offset ? i : offset + (i - offset) % period];
  }

  int offset, period;
  std::vector<std::array<int, 3>> values;
};

using Key = std::tuple<int, int, int>;

std::map<Key, Sg> cache;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x, y, z;
    scanf("%d%d%d%d", &n, &x, &y, &z);
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &a[i]);
    }
    Key key{x, y, z};
    auto iterator = cache.find(key);
    if (iterator == cache.end()) {
      iterator = cache.emplace(key, Sg{x, y, z}).first;
    }
    const Sg &sg = iterator->second;
    // int m = *std::max_element(a.begin(), a.end());
    // std::vector<std::array<int, 3>> sg(m + 1);
    // for (int i = 1; i <= m; ++i) {
    //   sg[i][0] = mex({
    //       i >= x ? sg[i - x][0] : 0,
    //       i >= y ? sg[i - y][1] : 0,
    //       i >= z ? sg[i - z][2] : 0,
    //   });
    //   sg[i][1] = mex({
    //       i >= x ? sg[i - x][0] : 0,
    //       i >= z ? sg[i - z][2] : 0,
    //   });
    //   sg[i][2] = mex({
    //       i >= x ? sg[i - x][0] : 0,
    //       i >= y ? sg[i - y][1] : 0,
    //   });
    // }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum ^= sg[a[i]][0];
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
      result += (sum ^ sg[a[i]][0] ^ (a[i] >= x ? sg[a[i] - x][0] : 0)) == 0;
      result += (sum ^ sg[a[i]][0] ^ (a[i] >= y ? sg[a[i] - y][1] : 0)) == 0;
      result += (sum ^ sg[a[i]][0] ^ (a[i] >= z ? sg[a[i] - z][2] : 0)) == 0;
    }
    printf("%d\n", result);
  }
}