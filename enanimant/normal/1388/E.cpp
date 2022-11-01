// July 30, 2020
// https://codeforces.com/contest/1388/problem/E
 
/*
 
*/
 
 
#include <bits/stdc++.h>
 
using namespace std;
 
 
const double EPS = 1e-9;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n;
  cin >> n;
  vector<int> xl(n), xr(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> xl[i] >> xr[i] >> y[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (y[i] != y[j]) {
      return y[i] > y[j];
    }
    return xl[i] < xl[j];
  });
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[order[i]] = i;
  }
  vector<pair<double, pair<int, int>>> events;
  vector<pair<double, double>> bad;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int b = order[i];
      int t = order[j];
      if (y[t] == y[b]) {
        continue;
      }
      double dy = y[t] - y[b];
      double m1 = (xl[b] - xr[t]) / dy;
      double m2 = (xr[b] - xl[t]) / dy;
      bad.emplace_back(m1, m2);
      events.emplace_back(m1, make_pair(-1, -1));
      events.emplace_back(m2, make_pair(b, t));
    }
  }
  events.emplace_back(0, make_pair(-1, -1));
  sort(bad.begin(), bad.end());
  sort(events.begin(), events.end());
  int r = -1;
  for (int i = 0; i < (int) bad.size(); i++) {
    if (r >= 0 && bad[i].first < bad[r].second - EPS) {
      bad[r].second = max(bad[r].second, bad[i].second);
    } else {
      bad[++r] = bad[i];
    }
  }
  int p = 0;
  double ans = 1e300;
  int left = order[0], right = order[n - 1];
  for (int eid = 0; eid < (int) events.size(); eid++) {
    const auto& e = events[eid];
    double m = e.first;
    int i, j;
    tie(i, j) = e.second;
    if (i != -1) {
      if (--pos[i] == 0) {
        left = i;
      }
      if (++pos[j] == n - 1) {
        right = j;
      }
    }
    if (eid + 1 < (int) events.size() && events[eid + 1].first - m < EPS) {
      continue;
    }
    while (p <= r && m > bad[p].second - EPS) {
      p++;
    }
    if (p > r || m < bad[p].first + EPS) {
      double x1 = xl[left] + m * y[left];
      double x2 = xr[right] + m * y[right];
      ans = min(ans, x2 - x1);
    }
  }
  cout.precision(10);
  cout << fixed;
  cout << ans << '\n';
  
  
  return 0;
}