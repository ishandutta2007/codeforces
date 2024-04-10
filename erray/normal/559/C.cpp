// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
const int md = (int) 1e9 + 7;
int add(int x, int y) {
  return (x + y) % md;
}

int sub(int x, int y) {
  return (x - y + md) % md;
}

int mul(int x, int y) {
  return 1LL * x * y % md;
}

int power(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = mul(res, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}

int divis(int x, int y) {
  return mul(x, power(y, md - 2));
}

vector<int> fact(1, 1);
int fac(int x) {
  while ((int) fact.size() <= x) {
    fact.push_back(mul(fact.back(), (int) fact.size()));
  }
  return fact[x];
}


int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i].first >> a[i].second;
    --a[i].first, --a[i].second;
  }
  sort(a.begin(), a.end());

  auto Way = [&](int x, int y) {
    return divis(divis(fac(x + y), fac(x)), fac(y));
  };

  vector<int> dp(k);
  int sum = 0;
  for (int i = 0; i < k; ++i) {
    auto[x, y] = a[i];
    dp[i] = Way(x, y);
    for (int j = 0; j < i; ++j) {
      auto[nx, ny] = a[j];
      if (ny > y) {
        continue;
      }
      dp[i] = sub(dp[i], mul(Way(x - nx, y - ny), dp[j]));
    }
    sum = add(sum, mul(dp[i], Way(n - 1 - x, m - 1 - y))); 
  }
  cout << sub(Way(n - 1, m - 1), sum) << '\n';
}