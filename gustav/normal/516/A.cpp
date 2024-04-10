#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

int n;
int f[10];
char buf[55];

int main(void) 
{
  for (int i = 2; i < 10; ++i) {
    if (f[i]) continue;
    for (int j = i + i; j < 10; j += i)
      f[j] = i;
  }

  scanf("%d", &n);
  scanf("%s", buf);

  vector< int > v;
  REP(i, n) {
    int x = buf[i] - '0';

    if (x == 0) continue;
    if (x == 1) continue;

    if (!f[x]) v.push_back(x);
    else {
      if (x == 4) v.push_back(2), v.push_back(2), v.push_back(3);
      if (x == 6) v.push_back(3), v.push_back(5);
      if (x == 8) v.push_back(7), v.push_back(2), v.push_back(2), v.push_back(2);
      if (x == 9) v.push_back(3), v.push_back(3), v.push_back(2), v.push_back(7);
    }
  }

  sort(v.rbegin(), v.rend());
  for (int x : v) printf("%d", x);
  puts("");
  
  return 0;
}