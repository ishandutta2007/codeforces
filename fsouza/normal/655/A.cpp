#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int getp() {
  char field[2][2];
  for (int y = 0; y < 2; ++y)
    for (int x = 0; x < 2; ++x)
      scanf(" %c", &field[y][x]);
  for (int y = 0; y < 2; ++y)
    for (int x = 0; x < 2; ++x)
      if (field[y][x] == 'X') {
	if (y+1 < 2)
	  swap(field[y][x], field[y+1][x]);
	else if (x+1 < 2)
	  swap(field[y][x], field[y][x+1]);
      }
  for (int y = 0; y < 2; ++y)
    for (int x = 0; x < 2; ++x)
      if (field[y][x] == 'X') {
	if (y+1 < 2)
	  swap(field[y][x], field[y+1][x]);
	else if (x+1 < 2)
	  swap(field[y][x], field[y][x+1]);
      }
  char seq[3] = {field[0][0], field[0][1], field[1][0]};
  int ninv = 0;
  for (int i = 0; i < 3; ++i)
    for (int j = i+1; j < 3; ++j)
      if (seq[i] > seq[j])
	++ninv;
  return ninv % 2;
}

int main() {
  int a = getp(), b = getp();
  printf(a == b ? "YES\n" : "NO\n");
  
  return 0;
}