/*
 * author:  ADMathNoob
 * created: 04/03/21 10:33:29
 * problem: https://codeforces.com/contest/1503/problem/C
 */

/*
g++ 1503C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1503C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  vector<int> na(n), nc(n);
  for (int i = 0; i < n; i++) {
    na[i] = a[order[i]];
    nc[i] = c[order[i]];
  }
  swap(a, na);
  swap(c, nc);
  int start = (int) (find(order.begin(), order.end(), 0) - order.begin());
  long long base = accumulate(c.begin(), c.end(), 0LL);
  vector<int> mx(n), bid(n);
  mx[0] = a[0] + c[0];
  bid[0] = 0;
  for (int i = 1; i < n; i++) {
    mx[i] = mx[i - 1];
    bid[i] = bid[i - 1];
    if (a[i] + c[i] > mx[i - 1]) {
      mx[i] = a[i] + c[i];
      bid[i] = i;
    }
  }
  auto GetBest = [&](int from, int to) {
    int v = from;
    long long res = 0;
    while (v < to) {
      int r = (int) (upper_bound(a.begin(), a.end(), mx[v]) - a.begin()) - 1;
      assert(r >= v);
      if (r == v) {
        res += a[v + 1] - mx[v];
        v = v + 1;
      } else {
        v = r;
      }
    }
    return res;
  };
  long long ans = min(GetBest(0, n - 1), GetBest(start, n - 1) + GetBest(0, start));
  ans += base;
  cout << ans << '\n';
  return 0;
}