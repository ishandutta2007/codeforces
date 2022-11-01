// April 23, 2020
// https://codeforces.com/contest/1340/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int INF = 1e9;
const int N = 10005; // m in problem statement since width doesn't really matter
const int G = 1005;

int w, n, g, r;
int d[N];
int dist[N][G];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> w >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  sort(d, d + n);
  n = unique(d, d + n) - d;
  cin >> g >> r;
  // dist[i][j] is congruent to j (mod (g + r))
  for (int i = 0; i < N; i++) {
    fill(dist[i], dist[i] + G, INF);
  }
  dist[0][0] = 0;
  deque<pair<int, int>> q;
  q.emplace_back(0, 0);
  while (!q.empty()) {
    int i, j;
    tie(i, j) = q.front();
    q.pop_front();
    for (int k = -1; k <= 1; k += 2) {
      int to = i + k;
      if (to < 0 || to >= n) {
        continue;
      }
      int nj = j + abs(d[i + k] - d[i]);
      if (nj > g) {
        continue;
      }
      nj %= g;
      int cost = (nj == 0);
      if (dist[i][j] + cost < dist[to][nj]) {
        dist[to][nj] = dist[i][j] + cost;
        if (cost == 0) {
          q.emplace_front(to, nj);
        } else {
          q.emplace_back(to, nj);
        }
      }
    }
  }
  long long ans = 1e18;
  for (int i = 0; i < n - 1; i++) {
    if (d[n - 1] - d[i] > g || dist[i][0] == INF) {
      continue;
    }
    ans = min(ans, 1LL * (g + r) * dist[i][0] + d[n - 1] - d[i]);
  }
  if (ans > 1e17) {
    ans = -1;
  }
  cout << ans << '\n';


  return 0;
}