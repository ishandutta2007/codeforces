/* Written by Filip Hlasek 2014 */
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

#define MAX 1000000000

bool printed = false;
void put_number(int n) {
  if (printed) printf(" ");
  printed = true;
  printf("%d", n);
}

int main(int argc, char *argv[]) {
  int n, k;
  scanf("%d%d", &n, &k);
  if (n / 2 > k) { printf("-1\n"); return 0; }
  if (n == 1) {
    if (k == 0) printf("1\n");
    else printf("-1\n");
    return 0;
  }
  REP(i, n / 2 - 1) { put_number(MAX - 2 * i); put_number(MAX - 2 * i - 1); k--; }
  put_number(k); put_number(2 * k);
  if (n & 1) put_number(MAX - n - 1);
  printf("\n");
  return 0;
}