#include <bits/stdc++.h>

const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 100'000;

struct Value {
  Value &operator+=(const Value &o) {
    add(cnt, o.cnt);
    add(sum, o.sum);
    return *this;
  }

  int cnt, sum;
};

std::pair<int, int> calc(int a, int u) {
  int k = (a + u - 1) / u;
  int end = (a + k - 1) / k;
  assert(end <= u);
  return {a / k, k - 1};
}

struct Vector : public std::vector<std::pair<int, Value>> {
  void append(int b, Value v) {
    if (empty() || back().first < b) {
      emplace_back(b, v);
    } else {
      back().second += v;
    }
  }
};

int n, a[N];
Vector dp[2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int result = 0;
    dp[n & 1].clear();
    for (int i = n; i--;) {
      dp[i & 1].clear();
      for (auto &&[u, v] : dp[(i + 1) & 1]) {
        add(result, v.sum);
        auto [begin, cost] = calc(a[i], u);
        dp[i & 1].append(
            begin,
            Value{v.cnt, static_cast<int>((1LL * cost * v.cnt + v.sum) % MOD)});
      }
      dp[i & 1].append(a[i], Value{1, 0});
    }
    for (auto &&[_, v] : dp[0]) {
      add(result, v.sum);
    }
    printf("%d\n", result);
  }
}