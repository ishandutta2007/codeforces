// September 25, 2020
// https://codeforces.com/contest/1420/problem/D

/*
g++ -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1420D.cpp && a
g++ -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1420D.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


struct Fenwick {
  int n;
  vector<int> fenw;

  Fenwick(int _n) : n(_n) {
    fenw.resize(n + 1, 0);
  }

  int get(int x) {
    int res = 0;
    for (x++; x > 0; x -= x & -x) {
      res += fenw[x];
    }
    return res;
  }

  void modify(int x, int v) {
    for (x++; x <= n; x += x & -x) {
      fenw[x] += v;
    }
  }
};

const int MOD = 998244353;

int power(long long b, long long e) {
  long long res = 1;
  while (e > 0) {
    if (e & 1) {
      res = res * b % MOD;
    }
    b = b * b % MOD;
    e >>= 1;
  }
  return res;
}

int inverse(int a) {
  return power(a, MOD - 2);
}

vector<long long> fact(1, 1);
vector<long long> inv_fact(1, 1);

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    int x = fact.back() * fact.size() % MOD;
    fact.push_back(x);
    inv_fact.push_back(inverse(x));
  }
  return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  vector<int> ts;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    // cin >> a[i].second >> a[i].first;
    ts.push_back(a[i].first);
    ts.push_back(a[i].second);
  }
  sort(ts.begin(), ts.end());
  ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
  for (int i = 0; i < n; i++) {
    a[i].first = (int) (lower_bound(ts.begin(), ts.end(), a[i].first) - ts.begin());
    a[i].second = (int) (lower_bound(ts.begin(), ts.end(), a[i].second) - ts.begin());
  }
  sort(a.begin(), a.end());
  int m = (int) ts.size();
  Fenwick ft(m);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = ft.get(m - 1) - ft.get(a[i].first - 1);
    ans = (ans + C(cnt, k - 1)) % MOD;
    ft.modify(a[i].second, 1);
  }
  cout << ans << '\n';


  return 0;
}