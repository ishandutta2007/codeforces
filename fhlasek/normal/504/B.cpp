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

#define MAXN 524288
int N;
int f[MAXN];

void add(int x, int val) {
  while (x < MAXN) {
    f[x] += val;
    x += x & -x;
  }
}

int get(int x) {
  int sum = 0;
  while (x) {
    sum += f[x];
    x -= x & -x;
  }
  return sum;
}

vector<int> read_perm() {
  REP(i, MAXN) f[i] = 0;
  vector<int> q;
  REP(i, N) {
    int p;
    scanf("%d", &p);
    q.push_back(p - get(p));
    add(p + 1, 1);
  }
  return q;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  vector<int> q1 = read_perm();
  vector<int> q2 = read_perm();
  int rem = 0;
  FORD(i, N - 1, 0) {
    int a = q1[i] + q2[i] + rem;
    rem = (a >= N - i);
    q1[i] = a % (N - i);
  }

  REP(i, MAXN) f[i] = 0;
  REP(i, N) {
    int q = q1[i];
    int l = q, r = N - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (m - get(m + 1) >= q) r = m;
      else l = m + 1;
    }
    add(l + 1, 1);
    if (i) printf(" ");
    printf("%d", l);
  }
  printf("\n");

  return 0;
}