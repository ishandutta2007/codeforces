#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int x, y;
  int winner = -1;

  scanf("%d %d", &x, &y);

  int turn = 0;
  while (winner == -1) {
    int tryx[2][3] = {{2,1,0},{0,1,2}};
    bool ok = false;

    for (int i = 0; i < 3; i++) {
      int vx = tryx[turn][i];
      int vy = (220 - vx * 100)/10;
      if (x >= vx && y >= vy) {
	x -= vx;
	y -= vy;
	ok = true;
	break;
      }
    }

    if (ok) turn ^= 1;
    else winner = turn ^ 1;
  }

  if (winner == 0) printf("Ciel\n");
  else printf("Hanako\n");

  return 0;
}