/*
 * author:  ADMathNoob
 * created: 02/07/21 08:39:23
 * problem: https://codeforces.com/contest/1479/problem/B2
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1479B2.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1479B2.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


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
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    --x;
    if (a.empty() || x != a.back()) {
      a.push_back(x);
    }
  }
  n = (int) a.size();
  auto as = a;
  sort(as.begin(), as.end());
  as.resize(unique(as.begin(), as.end()) - as.begin());
  for (int i = 0; i < n; i++) {
    a[i] = (int) (lower_bound(as.begin(), as.end(), a[i]) - as.begin());
  }
  vector<int> cur(n, n);
  vector<int> nex(n);
  for (int i = n - 1; i >= 0; i--) {
    nex[i] = cur[a[i]];
    cur[a[i]] = i;
  }

  vector<int> c(1, -1), d(1, -1);
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  c.push_back(0);
  d.push_back(1);
  for (int i = 2; i < n; i++) {
    assert(a[c.back()] != a[d.back()]);
    if (a[i] == a[c.back()]) {
      c.push_back(i);
    } else if (a[i] == a[d.back()]) {
      d.push_back(i);
    } else {
      if (nex[c.back()] < nex[d.back()]) {
        d.push_back(i);
      } else {
        c.push_back(i);
      }
    }
  }

  int ans = 0;
  for (int rot = 0; rot < 2; rot++) {
    for (int i = 1; i < (int) c.size(); i++) {
      c[i] = a[c[i]];
    }
    for (int i = 0; i < (int) c.size() - 1; i++) {
      if (c[i] != c[i + 1]) {
        ans += 1;
      }
    }
    swap(c, d);
  }
  cout << ans << '\n';


  return 0;
}