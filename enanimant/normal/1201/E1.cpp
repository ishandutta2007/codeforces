#include <bits/stdc++.h>

using namespace std;


const int N = 1000;
const int M = 1000;


int n, m;
int x[2], y[2]; // current positions
int tx[2], ty[2]; // targets
int p; // player that we are playing
pair<int, int> dirs[8] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int dist[2][N][M]; // distances from i's target
pair<int, int> last[2][N][M]; // last square in the bfs to i's target

bool in_range(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

void bfs(int sr, int sc, int (&dist)[N][M], pair<int, int> (&last)[N][M]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dist[i][j] = -1;
    }
  }
  queue<pair<int, int>> q;
  q.emplace(sr, sc);
  dist[sr][sc] = 0;
  while (!q.empty()) {
    int r, c;
    tie(r, c) = q.front();
    q.pop();
    for (const auto &d : dirs) {
      int nr = r + d.first, nc = c + d.second;
      if (!in_range(nr, nc) || dist[nr][nc] != -1) {
        continue;
      }
      dist[nr][nc] = dist[r][c] + 1;
      last[nr][nc].first = r;
      last[nr][nc].second = c;
      q.emplace(nr, nc);
    }
  }
}

bool attacking(int r1, int c1, int r2, int c2) {
  int dr = abs(r1 - r2), dc = abs(c1 - c2);
  if (dr > dc) {
    swap(dr, dc);
  }
  return dr == 1 && dc == 2;
}

bool attacking() {
  return attacking(x[0], y[0], x[1], y[1]);
}

bool game_over() {
  return (x[p] == tx[p] && y[p] == ty[p]) || (x[0] == x[1] && y[0] == y[1]);
}

int move_to(int r, int c) {
  assert(attacking(r, c, x[p], y[p]));
  x[p] = r;
  y[p] = c;
  cout << r << ' ' << c << endl;
}

void read_coords() {
  cin >> x[p ^ 1] >> y[p ^ 1];
  x[p ^ 1]--;
  y[p ^ 1]--;
}

void print_coords() {
  cout << x[p] + 1 << ' ' << y[p] + 1 << endl;
}

void set_player(int pp) {
  p = pp;
  if (p == 0) {
    cout << "WHITE" << endl;
  } else {
    cout << "BLACK" << endl;
    read_coords();
  }
}

void move_to(int t) {
  while (x[p] != tx[t] || y[p] != ty[t]) {
    if (attacking()) {
      p ^= 1;
      print_coords();
      exit(0);
    }
    tie(x[p], y[p]) = last[t][x[p]][y[p]];
    print_coords();
    if (game_over()) {
      exit(0);
    }
    read_coords();
  }
}

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

#ifdef _DEBUG
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m;
  for (int i = 0; i < 2; i++) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  tx[0] = n / 2 - 1;
  tx[1] = n / 2;
  ty[0] = ty[1] = m / 2 - 1;
  for (int i = 0; i < 2; i++) {
    bfs(tx[i], ty[i], dist[i], last[i]);
  }
  int d[2][2]; // d[i][j]: dist from player i to j's target
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      d[i][j] = dist[j][x[i]][y[i]];
    }
  }
  if (d[0][0] <= d[1][1] && (d[0][0] < d[1][0] || (d[0][0] % 2 != d[1][0] % 2))) {
    cerr << "white, go to target\n";
    set_player(0);
    move_to(0);
    return 0;
  }
  if (d[1][1] < d[0][0] && (d[1][1] < d[0][1] - 1 || (d[0][0] % 2 == d[1][0] % 2))) {
    cerr << "black, go to target\n";
    set_player(1);
    move_to(1);
    return 0;
  }
  // it's more or less a tie; never get captured
  if ((x[0] + y[0]) % 2 == (x[1] + y[1]) % 2) {
    set_player(1);
  } else {
    set_player(0);
  }
  move_to(p ^ 1);
  move_to(p);


  return 0;
}