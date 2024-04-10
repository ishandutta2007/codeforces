#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
  int r, c;
  cin >> r >> c;
  vector<string> field(r);
  for (int i = 0; i < r; i++) cin >> field[i];

  vector<bool> badr(r), badc(c);

  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++)
      if (field[y][x] == 'S')
	badr[y] = badc[x] = true;

  int ret = 0;

  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++)
      if (field[y][x] != 'S' && (!badr[y] || !badc[x]))
	ret++;

  cout << ret << endl;

  return 0;
}