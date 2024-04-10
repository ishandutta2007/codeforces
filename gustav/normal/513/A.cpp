#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

int main(void) 
{
  int n1, n2;
  scanf("%d%d", &n1, &n2);

  int k1, k2;
  scanf("%d%d", &k1, &k2);

  int player = 1;
  while (true) {
    if (player == 1) {
      if (n1 == 0) {
	puts("Second");
	exit(0);
      } else {
	--n1;
      }
    } else {
      if (n2 == 0) {
	puts("First");
	exit(0);
      } else {
	--n2;
      }
    }
    player = 3 - player;
  }
  
  return 0;
}