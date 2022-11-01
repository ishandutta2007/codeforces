#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

map <pair <pii, ll>, ll> cnt;

ll ans = 0;
ll board[20][20];

int n, m;
ll k;

void dfs0(int x, int y, ll curxor) {
  if (x >= n || y >= m)
    return;
  curxor ^= board[x][y];
  if (x + y == m - 1) {
    cnt[{{x, y}, curxor}]++;
    return;
  }
  dfs0(x + 1, y, curxor);
  dfs0(x, y + 1, curxor);
}

int sx, sy;

void dfs1(int x, int y, ll curxor) {
  if (x >= n || y >= m)
    return;
  curxor ^= board[x][y];
  if (x == n - 1 && y == m - 1) {
    ans += cnt[{{sx, sy}, curxor ^ k}];
    return;
  }
  dfs1(x + 1, y, curxor);
  dfs1(x, y + 1, curxor);
}

int main() {
  cin >> n >> m;
  cin >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  dfs0(0, 0, 0);
  for (int i = 0; i < m; i++) {
    sx = i, sy = (m - 1) - i;
    dfs1(i, (m - 1) - i, board[sx][sy]);
  }
  cout << ans;
  return 0;
}