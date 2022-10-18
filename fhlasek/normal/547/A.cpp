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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111
// Chinese remainder theorem
// x = a1 (mod n1) && x = a2 (mod n2)  =>  x = ans (mod n1 * n2)
long long chinese(long long a1, long long n1, long long a2, long long n2) {
  if (n1 == -1 && n2 == -1) return a1 == a2 ? a1 : -1;
  if (n1 == -1) { swap(n1, n2); swap(a1, a2); }
  if (n2 == -1) {
    while (a1 < a2) a1 += n1;
    return a1 == a2 ? a1 : -1;
  }
  REP(x1, 2 * MAXN) if ((n1 * x1 + a1) % n2 == a2 % n2 && n1 * x1 + a1 >= a2) return n1 * x1 + a1;
  return -1;
}

bool vis[MAXN];
long long when(long long h, long long a, long long x, long long y, long long m, bool start) {
  REP(i, m) vis[i] = false;
  long long ans = 0;
  if (start) {
    ans++;
    vis[h] = true;
    h = (x * h + y) % m;
  }
  while (h != a && !vis[h]) {
    vis[h] = true;
    ans++;
    h = (x * h + y) % m;
  }
  if (h != a) return -1;
  return ans;
}

long long solve(int m, int h1, int a1, int x1, int y1, int h2, int a2, int x2, int y2) {
  long long A1 = when(h1, a1, x1, y1, m, 0);
  long long n1 = when(a1, a1, x1, y1, m, 1);
  long long A2 = when(h2, a2, x2, y2, m, 0);
  long long n2 = when(a2, a2, x2, y2, m, 1);

  if (A1 == -1 || A2 == -1) return -1;
  return chinese(A1, n1, A2, n2);;
}

long long slow(int m, int h1, int a1, int x1, int y1, int h2, int a2, int x2, int y2) {
  int ans = 0;
  while (ans < 1000000) {
    if (h1 == a1 && h2 == a2) return ans;
    ans++;
    h1 = ((long long)h1 * x1 + y1) % m;
    h2 = ((long long)h2 * x2 + y2) % m;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  int m, h1, a1, x1, y1, h2, a2, x2, y2;
  scanf("%d%d%d%d%d%d%d%d%d", &m, &h1, &a1, &x1, &y1, &h2, &a2, &x2, &y2);
  /*
  while (true) {
    m = rand() % 20 + 2;
    h1 = rand() % m; a1 = rand() % m; x1 = rand() % m; y1 = rand() % m;
    h2 = rand() % m; a2 = rand() % m; x2 = rand() % m; y2 = rand() % m;
    if (h1 == a1 || h2 == a2) continue;
    if (slow(m, h1, a1, x1, y1, h2, a2, x2, y2) != solve(m, h1, a1, x1, y1, h2, a2, x2, y2)) {
      printf("%d, %d %d %d %d, %d %d %d %d\n", m, h1, a1, x1, y1, h2, a2, x2, y2);
      break;
    }
  }
  */
  // cout << slow(m, h1, a1, x1, y1, h2, a2, x2, y2) << endl;
  cout << solve(m, h1, a1, x1, y1, h2, a2, x2, y2) << endl;
  return 0;
}