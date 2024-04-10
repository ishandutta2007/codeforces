// August 7, 2019
// https://codeforces.com/contest/1202/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


int n;
string s;
vector<int> v;
int dist[10];
int ans[10][10];

void bfs(int a, int b) {
  vector<int> nxt = {a, b};
  queue<int> q;
  fill(dist, dist + 10, -1);
  dist[a] = dist[b] = 0;
  q.push(a);
  q.push(b);
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (int x : nxt) {
      int u = (s + x) % 10;
      if (dist[u] != -1) {
        continue;
      }
      dist[u] = dist[s] + 1;
      q.push(u);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> s;
  for (char c : s) {
    v.push_back(c - '0');
  }
  n = (int) v.size();
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j <= i; j++) {
      bfs(i, j);
      int cur = 0;
      int res = 0;
      bool poss = true;
      for (int k = 1; k < n; k++) {
        int d = (v[k] - v[k - 1] + 10) % 10;
        if (dist[d] == -1) {
          poss = false;
        }
        res += dist[d];
      }
      if (!poss) {
        res = -1;
      }
      ans[i][j] = res;
      ans[j][i] = res;
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << ans[i][j] << (j < 9 ? ' ' : '\n');
    }
  }


  return 0;
}