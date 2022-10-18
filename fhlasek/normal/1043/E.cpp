/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

struct Person {
  int x, y, id;
  long long ans;
};

#define MAXN 333333
Person p[MAXN];

int N, M;

long long prefX[MAXN], suffY[MAXN];

bool cmp1(const Person& a, const Person& b) {
  return (a.x - a.y) < (b.x - b.y);
}

bool cmp2(const Person& a, const Person& b) {
  return a.id < b.id;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) {
    scanf("%d%d", &p[i].x, &p[i].y);
    p[i].id = i;
    p[i].ans = 0;
  }
  while (M--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    int score = min(p[u].x + p[v].y, p[u].y + p[v].x);
    p[u].ans -= score;
    p[v].ans -= score;
  }

  sort(p, p + N, cmp1);

  REP(i, N) prefX[i + 1] = prefX[i] + p[i].x;
  REP(i, N) suffY[N - i - 1] = suffY[N - i] + p[N - i - 1].y;
  REP(i, N) {
    p[i].ans += (long long)i * p[i].y + prefX[i] + (long long)(N - i - 1) * p[i].x + suffY[i + 1];
  }

  sort(p, p + N, cmp2);
  REP(i, N) {
    if (i) cout << " ";
    cout << p[i].ans;
  }
  cout << endl;
  return 0;
}