#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
const int ms = 505;

string s[ms];
pair<int, int> pos[ms*ms];
int vis[ms][ms], z;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int n, m, k;

void dfs(int i, int j) {
  if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || s[i][j] == '#') return;
  vis[i][j] = 1;
  pos[z++] = {i, j};
  for(int d = 0; d < 4; d++) {
    dfs(i + dx[d], j + dy[d]);
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < n; i++) {
    for(int j =0 ; j < m; j++) {
      dfs(i, j);
    }
  }
  reverse(pos, pos + z);
  for(int i = 0; i < k; i++) {
    s[pos[i].first][pos[i].second] = 'X';
  }
  for(int i =0 ; i < n; i++) cout << s[i] << '\n';
}