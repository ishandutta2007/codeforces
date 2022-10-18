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

const int inf = 2000000000;
const int MAX = 1005;

int n;
int w[MAX];
int h[MAX];

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) 
    scanf("%d%d", w+i, h+i);

  int sol = inf;
  FOR(H, 1, MAX) {
    bool ok = true;
    int cnt_bad = 0;
    int W = 0;

    REP(i, n) {
      if (h[i] > H) {
	if (w[i] > H) {
	  ok = false;
	} else {
	  cnt_bad += 1;
	  W += h[i];
	}
      } else {
	W += w[i];
      }
    }

    if (!ok) continue;
    if (cnt_bad * 2 > n) continue;

    vector< int > ws;

    REP(i, n) {
      if (h[i] > H) continue;
      if (h[i] < w[i] && w[i] <= H) ws.push_back(h[i] - w[i]);
    }

    sort(ws.begin(), ws.end());

    for (int d : ws) 
      if ((cnt_bad + 1) * 2 <= n) 
	W += d, ++cnt_bad;

    sol = min(sol, W * H);
  }

  printf("%d\n", sol);

  return 0;
}