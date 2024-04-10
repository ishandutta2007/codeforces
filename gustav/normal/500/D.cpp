#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;

int N, Q;

struct Edge { int to, id; };

vector< Edge > T[MAXN];
int w[MAXN];
double p[MAXN]; 

double ch1(int n) {
  return (double)n;
}

double ch2(int n) {
  return (double)n * (n - 1) / 2.0;
}

double ch3(int n) {
  return (double)n * (n - 1) * (n - 2) / 6.0;
}

int dfs(int n, int dad) {
  int ret = 1;

  for (auto e : T[n]) {
    if (e.to == dad) continue;
    int down = dfs(e.to, n);
    int up = N - down;

    p[e.id] += ch1(down) * ch2(up);
    p[e.id] += ch2(down) * ch1(up);
    p[e.id] /= ch3(N);

    ret += down;
  }

  return ret;
}

int main(void) 
{
  scanf("%d", &N);

  REP(i, N - 1) {
    int a, b;
    scanf("%d%d%d", &a, &b, w + i); --a; --b;
    T[a].push_back({b, i});
    T[b].push_back({a, i});
  }

  dfs(0, -1);

  double sol = 0.0;
  REP(i, N - 1) sol += 2.0 * p[i] * w[i];

  scanf("%d", &Q);

  REP(i, Q) {
    int r, nw;
    scanf("%d%d", &r, &nw); --r;

    sol -= 2.0 * p[r] * w[r];
    w[r] = nw;
    sol += 2.0 * p[r] * w[r];

    printf("%.10lf\n", sol);
  }

  return 0;
}