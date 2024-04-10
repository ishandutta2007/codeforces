#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int IT = 1000000;

int main(void) 
{
  int C, Hr, Hb, Wr, Wb;
  scanf("%d%d%d%d%d", &C, &Hr, &Hb, &Wr, &Wb);

  llint sol = 0;
  REP(rot, 2) {
    REP(r, IT) {
      if ((llint)r * Wr > C) break;
      llint b = (C - (llint)Wr * r) / Wb;
      sol = max(sol, (llint)Hr * r + (llint)Hb * b);
    }
    swap(Hr, Hb);
    swap(Wr, Wb);
  }

  printf("%lld\n", sol);


  return 0;
}