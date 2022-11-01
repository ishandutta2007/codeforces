// August 23, 2019
// https://codeforces.com/contest/1037/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 200005;


int n;
vector<int> g[N];
vector<int> a;
int pos[N];
bool was[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    pos[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    sort(g[i].begin(), g[i].end(), [](int a, int b) {
      return pos[a] < pos[b];
    });
  }
  vector<int> order(1, 0);
  was[0] = true;
  for (int ptr = 0; ptr < n; ptr++) {
    int v = order[ptr];
    for (int to : g[v]) {
      if (was[to]) {
        continue;
      }
      was[to] = true;
      order.push_back(to);
    }
  }
  cout << (order == a ? "Yes" : "No") << '\n';


  return 0;
}