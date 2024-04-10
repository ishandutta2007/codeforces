#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
  const int X = pow(1e9 / 2, 1. / 3), Y = pow(1e9, 1. / 4);

  vector<int> primes;
  vector<bool> vis(X + 1);
  for (int i = 2; i <= X; ++i) {
    if (!vis[i]) {
      primes.push_back(i);
      for (int j = i; j <= X; j += i)
        vis[j] = true;
    }
  }
  reverse(primes.begin(), primes.end());
  vector<vector<int>> g1, g2;
  while (!primes.empty()) {
    ll cur = 1;
    vector<int> group;
    while (!primes.empty() && cur <= 1e18 / primes.back()) {
      cur *= primes.back();
      group.push_back(primes.back());
      primes.pop_back();
    }
    if (group.back() < Y) g1.push_back(group);
    else g2.push_back(group);
  }

  auto ask = [&](const vector<int> &vi) {
    cout << "? " << accumulate(vi.begin(), vi.end(), 1LL, multiplies<ll>()) << endl;
    vector<int> ret;
    ll res;
    cin >> res;
    for (int p : vi)
      if (res % p == 0) {
        res /= p;
        ret.push_back(p);
      }
    return ret;
  };

  auto col = [&](const vector<int> &vi) {
    ll val = 1;
    for (int p : vi) {
      ll cur = 1;
      while (cur * p <= 1e9) cur *= p;
      val *= cur;
    }
    cout << "? " << val << endl;
    ll res;
    cin >> res;
    vector<pair<int, int>> ret;
    for (int p : vi) {
      int cnt = 0;
      while (res % p == 0) {
        res /= p;
        ++cnt;
      }
      ret.emplace_back(p, cnt);
    }
    return ret;
  };

  int t;
  cin >> t;
  while (t--) {
    vector<int> prs;
    for (auto gr : g1) {
      auto res = ask(gr);
      prs.insert(prs.end(), res.begin(), res.end());
    }
    if (prs.empty()) {
      cout << "! 8" << endl;
      continue;
    }
    vector<pair<int, int>> pf;
    int cur = 1, ans = 1;
    for (int p : prs) {
      auto res = col({p})[0].second;
      pf.emplace_back(p, res);
      cur *= pow(p, res);
      ans *= res + 1;
    }
    int LIM = pow(1e9 / cur, (1. + 1e-7) / 3);
    prs.clear();
    for (auto gr : g2) {
      auto res = ask(gr);
      prs.insert(prs.end(), res.begin(), res.end());
      if (gr.back() > LIM) break;
    }
    while (!prs.empty()) {
      vector<int> pr2;
      for (int rep = 0; rep < 2; ++rep) {
        pr2.push_back(prs.back());
        prs.pop_back();
        if (prs.empty()) break;
      }
      auto res = col(pr2);
      for (auto [x, y] : res)
        ans *= y + 1;
    }
    cout << "! " << (ans * 2) << endl;
  }

  return 0;
}