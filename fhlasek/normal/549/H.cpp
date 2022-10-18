/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

long double a, b, c, d;

bool is_ok(long double norm) {
  long double ma = a * d, Ma = a * d, mb = b * c, Mb = b * c;

  ma = min(ma, (a - norm) * d);
  ma = min(ma, (a + norm) * d);
  ma = min(ma, a * (d - norm));
  ma = min(ma, a * (d + norm));
  ma = min(ma, (a - norm) * (d - norm));
  ma = min(ma, (a - norm) * (d + norm));
  ma = min(ma, (a + norm) * (d - norm));
  ma = min(ma, (a + norm) * (d + norm));

  Ma = max(Ma, (a - norm) * d);
  Ma = max(Ma, (a + norm) * d);
  Ma = max(Ma, a * (d - norm));
  Ma = max(Ma, a * (d + norm));
  Ma = max(Ma, (a - norm) * (d - norm));
  Ma = max(Ma, (a - norm) * (d + norm));
  Ma = max(Ma, (a + norm) * (d - norm));
  Ma = max(Ma, (a + norm) * (d + norm));

  mb = min(mb, (b - norm) * c);
  mb = min(mb, (b + norm) * c);
  mb = min(mb, b * (c - norm));
  mb = min(mb, b * (c + norm));
  mb = min(mb, (b - norm) * (c - norm));
  mb = min(mb, (b - norm) * (c + norm));
  mb = min(mb, (b + norm) * (c - norm));
  mb = min(mb, (b + norm) * (c + norm));

  Mb = max(Mb, (b - norm) * c);
  Mb = max(Mb, (b + norm) * c);
  Mb = max(Mb, b * (c - norm));
  Mb = max(Mb, b * (c + norm));
  Mb = max(Mb, (b - norm) * (c - norm));
  Mb = max(Mb, (b - norm) * (c + norm));
  Mb = max(Mb, (b + norm) * (c - norm));
  Mb = max(Mb, (b + norm) * (c + norm));
  // printf("%Lf %Lf, %Lf, %Lf\n", ma, Ma, mb, Mb);
  if (ma <= mb && mb <= Ma) return true;
  if (mb <= ma && ma <= Mb) return true;
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);
  long double l = 0, r = 1000000007LL;
  REP(i, 1000) {
    long double m = (l + r) / 2;
    if (is_ok(m)) r = m;
    else l = m;
  }
  printf("%.12Lf\n", (l + r) / 2);
  return 0;
}