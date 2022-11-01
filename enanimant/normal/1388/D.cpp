// July 30, 2020
// https://codeforces.com/contest/1388/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 200005;

int n;
long long a[N];
int succ[N];

int indeg[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> succ[i];
    if (succ[i] != -1) {
      succ[i]--;
      indeg[succ[i]]++;
    }
  }
  vector<int> c;
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      c.push_back(i);
    }
  }
  long long ans = 0;
  vector<int> order, rev;
  for (int j = 0; j < (int) c.size(); j++) {
    int v = c[j];
    int to = succ[v];
    if (a[v] >= 0) {
      order.push_back(v);
      a[to] += a[v];
    } else {
      rev.push_back(v);
    }
    ans += a[v];
    if (--indeg[to] == 0) {
      c.push_back(to);
    }
    succ[v] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (succ[i] != -1) {
      vector<long long> cycle;
      int v = i;
      long long sum = 0;
      do {
        cycle.push_back(a[v]);
        sum += a[v];
        v = succ[v];
      } while (v != i);
      int s = (int) cycle.size();
      long long cur = 0;
      for (int j = 0; j < s; j++) {
        cur += a[j] * (n - j);
      }
      long long best = 0;
      int start = 0;
      for (int j = 0; j < s; j++) {
        if (cur > best) {
          best = cur;
          start = j;
        }
        cur += sum;
        cur -= a[j] * n;
      }
      ans += best;
      for (int j = 0; j < s; j++) {
        int u = cycle[(start + j) % s];
        c.push_back(u);
        succ[u] = -1;
      }
    }
  }
  cout << ans << '\n';
  order.insert(order.end(), rev.rbegin(), rev.rend());
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << order[i] + 1;
  }
  cout << '\n';
  
  
  return 0;
}