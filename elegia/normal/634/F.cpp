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

#define X first
#define Y second

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int R, C, k;
ll ans;

void solve(int l, int r, vector<pair<int, int>> orch) {
  if (l > r) return;
  vector<int> ys;
  for (const auto& pr : orch) ys.push_back(pr.Y);
  int mid = (l + r) / 2;
  if (!ys.empty()) {
    nth_element(ys.begin(), ys.begin() + ys.size() / 2, ys.end());
    mid = ys[ys.size() / 2];
  }
  vector<pair<int, int>> left, right;
  vector<int> lstk, rstk;
  int cnt = 0;
  int lx = 1;
  function<void(int)> calc = [&](int con) {
    if (cnt >= k) return;
    int p = rstk.size();
    for (int i = 0; i <= lstk.size(); ++i) {
      while (i + p + cnt >= k) --p;
      while (p > 0 && p < rstk.size() && rstk[p - 1] == rstk[p]) --p;
      if (p < 0) break;
      int llen = (i == 0 ? mid : lstk[i - 1]) - (i == lstk.size() ? l - 1 : lstk[i]);
      int rlen = (p == rstk.size() ? r : rstk[p] - 1) - (mid - 1);
      ans += llen * (ll)rlen * con;
//      cerr << llen << " * " << rlen << " * " << con << '\n';
    }
  };
  for (const auto& p : orch)
    if (p.Y < mid) {
      left.push_back(p);
    } else if (p.Y > mid) {
      right.push_back(p);
    }
  for (int i = 0; i <= orch.size(); ++i) {
    lstk.clear(); rstk.clear(); cnt = 0; lx = 1 + ((i == 0) ? 0 : orch[i - 1].X);
    int con = (i == orch.size() ? R : orch[i].X) - (i == 0 ? 0 : orch[i - 1].X);
    if (!con) continue;
    for (int j = i; j < orch.size(); ++j) {
      const auto& p = orch[j];
      if (p.X > lx) {
        if (j == i) {
//          cerr << "assert " << con << ' ' << (p.X - lx) << '\n';
          calc(con * (con - 1) / 2);
        } else {
          calc((p.X - lx) * con);
        }
        lx = p.X;
      }
      if (p.Y == mid)
        ++cnt;
      else if (p.Y < mid) {
        lstk.insert(lower_bound(lstk.begin(), lstk.end(), p.Y, greater<int>()), p.Y);
        if (lstk.size() > k) lstk.pop_back();
      } else if (p.Y > mid) {
        rstk.insert(lower_bound(rstk.begin(), rstk.end(), p.Y), p.Y);
        if (rstk.size() > k) rstk.pop_back();
      }
    }
    if (i == orch.size())
      calc(con * (con + 1) / 2);
    else
      calc((R + 1 - lx) * con);
  }
  solve(l, mid - 1, left);
  solve(mid + 1, r, right);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> R >> C >> n >> k;
  vector<pair<int, int>> orch(n);
  for (int i = 0; i < n; ++i) cin >> orch[i].X >> orch[i].Y;
  sort(orch.begin(), orch.end());
  solve(1, C, orch);
  ans = (R * (R + 1LL) / 2) * (C * (C + 1LL) / 2) - ans;
  cout << ans;

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}