#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int decode(char c) {
  switch (c) {
    case '+':
      return 0b1111;
    case '-':
      return 0b1010;
    case '|':
      return 0b0101;
    case '^':
      return 0b0100;
    case '>':
      return 0b1000;
    case '<':
      return 0b0010;
    case 'v':
      return 0b0001;
    case 'L':
      return 0b1101;
    case 'R':
      return 0b0111;
    case 'U':
      return 0b1011;
    case 'D':
      return 0b1110;
    case '*':
      return 0;
    default:
      return 0;
  }
}

const int inf = 5000000;

struct Pos {
  int x, y;
  int rot;
  Pos() : x(0), y(0), rot(0) {}
  Pos(int x, int y, int rot) : x(x), y(y), rot(rot) {}
};

int getMask(int mask, int rot) {
  mask <<= rot;
  return (mask | (mask >> 4)) & 15;
}

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<std::vector<int>> graph(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    std::string s;
    in >> s;
    for (int j = 0; j < m; j++) {
      graph[i][j] = decode(s[j]);
    }
  }
  int xT, yT;
  in >> xT >> yT;
  xT--;
  yT--;
  int xM, yM;
  in >> xM >> yM;
  xM--;
  yM--;
  std::vector<std::vector<std::array<int, 4>>> dist(n, std::vector<std::array<int, 4>>(m, {inf, inf, inf, inf}));
  std::vector<Pos> queue(n * m * 4);
  int bque = 0;
  int eque = 1;
  queue[0].x = xT;
  queue[0].y = yT;
  queue[0].rot = 0;
  dist[xT][yT][0] = 0;
  while (eque > bque) {
    Pos& pos = queue[bque];
    int d = dist[pos.x][pos.y][pos.rot];
    bque++;
    for (int dir = 0; dir < 4; dir++) {
      int nx = pos.x + dx[dir];
      int ny = pos.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        continue;
      }
      if (dist[nx][ny][pos.rot] <= d + 1) {
        continue;
      }
      if ((getMask(graph[pos.x][pos.y], pos.rot) & (1 << dir)) == 0 ||
          (getMask(graph[nx][ny], pos.rot) & (1 << (dir ^ 2))) == 0) {
        continue;
      }
      queue[eque].x = nx;
      queue[eque].y = ny;
      queue[eque].rot = pos.rot;
      dist[nx][ny][pos.rot] = d + 1;
      eque++;
    }
    if (dist[pos.x][pos.y][(pos.rot + 1) & 3] > d + 1) {
      queue[eque] = pos;
      queue[eque].rot = (pos.rot + 1) & 3;
      dist[pos.x][pos.y][(pos.rot + 1) & 3] = d + 1;
      eque++;
    }
  }
  int ans = inf;
  for (int rot = 0; rot < 4; rot++) {
    ans = std::min(ans, dist[xM][yM][rot]);
  }
  if (ans == inf) ans = -1;
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}