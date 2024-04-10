#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXT = 24 * 60 * 60;

int n, M, T;
vector< int > t[MAXT];
int sol[MAXT];

int main(void) 
{
  scanf("%d%d%d", &n, &M, &T);

  REP(i, n) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    h = h * 60 + m;
    h = h * 60 + s;
    t[h].push_back(i);
  }

  bool ok = false;
  int id = 1;
  deque< int > q;
  REP(i, MAXT) {
    while (!q.empty() && q.front() <= i - T) q.pop_front();
    while (!t[i].empty() && (int)q.size() < M) {
      sol[t[i].back()] = id++;
      q.push_back(i);
      t[i].pop_back();
    }
    while (!t[i].empty()) {
      sol[t[i].back()] = id - 1;
      q.pop_back();
      q.push_back(i);
      t[i].pop_back();
    }
    if ((int)q.size() == M)
      ok = true;
  }

  if (ok) {
    printf("%d\n", id - 1);
    REP(i, n) printf("%d\n", sol[i]);
  } else {
    puts("No solution");
  }

  return 0;
}