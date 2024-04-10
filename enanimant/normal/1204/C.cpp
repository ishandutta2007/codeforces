// August 20, 2019
// https://codeforces.com/contest/1204/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int INF = 1e9;
const int N = 105;
const int M = 1000005;


int n, m;
int p[M];
int g[N][N];
int dist[N][N];

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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      g[i][j] = c - '0';
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        dist[i][j] = 0;
      } else if (g[i][j]) {
        dist[i][j] = 1;
      } else {
        dist[i][j] = INF;
      }
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  vector<int> ans(2);
  ans[0] = 0;
  ans[1] = 1;
  int k = 2;
  for (int i = 2; i < m; i++) {
    if (dist[p[ans[k - 2]]][p[i]] == dist[p[ans[k - 2]]][p[ans[k - 1]]] + dist[p[ans[k - 1]]][p[i]]) {
      ans.back() = i;
    } else {
      ans.push_back(i);
      k++;
    }
  }
  cout << k << '\n';
  for (int i = 0; i < k; i++) {
    cout << p[ans[i]] + 1 << (i < k - 1 ? ' ' : '\n');
  }


  return 0;
}