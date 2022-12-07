#include <iostream>
#include <cstdio>

using namespace std;

int n;
unsigned int r[2000][70];
unsigned int c[2000][70];
unsigned int visr[2000][70];
unsigned int visc[2000][70];

bool go(int x, int y) {
  visr[x][y >> 5] ^= (unsigned int) 1 << (y & 31);
  visc[y][x >> 5] ^= (unsigned int) 1 << (x & 31);
  if (r[x][y >> 5] & ((unsigned int) 1 << (y & 31)))
    return true;
  for (int i = 0; i <= (n >> 5); ++i)
    if (r[x][i] & c[y][i]) {
      r[x][y >> 5] |= (unsigned int) 1 << (y & 31);
      c[y][x >> 5] |= (unsigned int) 1 << (x & 31);
      return true;
    }
  for (int i = 0; i <= (n >> 5); ++i) {
    unsigned int o = 1;
    unsigned int z = 0;
    for (unsigned int p = r[x][i] & visc[y][i]; p; p &= p - 1) {
      while (!(o & p)) {
        o <<= 1;
        ++z;
      }
      if (go((i << 5) | z, y)) {
        r[(i << 5) | z][y >> 5] |= (unsigned int) 1 << (y & 31);
        c[y][x] |= (unsigned int) 1 << z;
        return true;
      }
    }
  }
  for (int i = 0; i <= (n >> 5); ++i) {
    unsigned int o = 1;
    unsigned int z = 0;
    for (unsigned int p = c[y][i] & visr[x][i]; p; p &= p - 1) {
      while (!(o & p)) {
        o <<= 1;
        ++z;
      }
      if (go(x, (i << 5) | z)) {
        c[(i << 5) | z][x >> 5] |= (unsigned int) 1 << (x & 31);
        r[x][y] |= (unsigned int) 1 << z;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= (n >> 5); ++j) {
      r[i][j] = 0;
      c[i][j] = 0;
    }
  int x;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &x);
      if (x) {
        r[i][j >> 5] |= (unsigned int)1 << (j & 31);
        c[j][i >> 5] |= (unsigned int)1 << (i & 31);
      }
      visr[i][j >> 5] |= (unsigned int)1 << (j & 31);
      visc[j][i >> 5] |= (unsigned int)1 << (i & 31);
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (visr[i][j >> 5] & ((unsigned int)1 << (j & 31))) {
        if (!go(i, j)) {
          cout << "NO" << endl;
          return 0;
        }
      }
  cout << "YES" << endl;
  return 0;
}