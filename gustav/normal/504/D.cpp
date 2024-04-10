#include <cstdio>
#include <cassert>
#include <bitset>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXM = 2005;
const int P2BASE = 1 << 16;
typedef bitset< 2000 > Num;


Num M[MAXM];
Num T[MAXM];
int bits[2000 / 16], top;

void clear() {
  top = 1;
  memset(bits, 0, sizeof bits);
}

void trim() {
  for (int i = 0; i < top; ++i) {
    if (bits[i] >= P2BASE) {
      if (i + 1 == top) ++top;
      bits[i + 1] += bits[i] / P2BASE;
      bits[i] %= P2BASE;
    }
  }
}

void mul(int b) {
  REP(i, top) bits[i] *= b;
  trim();
}

void add(int v) {
  bits[0] += v;
  trim();
}

Num get() {
  Num ret;
  REP(i, top) {
    REP(j, 16) {
      ret[i * 16 + j] = ((bits[i] >> j) & 1);
    }
  }
  return ret;
}

char buf[700];
int which[2000];

int main(void) 
{
  int m;
  scanf("%d", &m);

  vector< int > got;

  REP(i, m) {
    scanf("%s", buf);
    int n = strlen(buf);
    
    clear();

    for (int j = 0, k; j < n; j = k) {
      for (k = j; (n - 1 - k) % 4 != 0; ++k);
      ++k;

      int cur = 0;
      FOR(l, j, k) cur = cur * 10 + buf[l] - '0';

      mul(10000);
      add(cur);
    }

    M[i] = get();

    T[i][i] = 1;

    for (int bit : got) {
      if (M[i][bit]) {
	M[i] ^= M[which[bit]];
	T[i] ^= T[which[bit]];
      }
    }

    int biggest = 1999;
    while (biggest >= 0 && !M[i][biggest]) --biggest;

    if (biggest == -1) {
      int cnt = -1;
      REP(j, 2000) cnt += T[i][j];
      printf("%d ", cnt);
      REP(j, 2000) if (T[i][j] && i != j) printf("%d ", j);
      puts("");
    } else {
      puts("0");
      which[biggest] = i;
      got.push_back(biggest);
      REP(j, i) if (M[j][biggest]) M[j] ^= M[i], T[j] ^= T[i];
    }
  }

  return 0;
}