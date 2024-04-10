#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;
typedef long long llint;
typedef pair< llint, llint > pt;

#define PS 40
#define ITER 10
#define MAXN 100005

int N;
int a[MAXN];

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) 
    scanf("%d", a + i);

  vector< pt > p;

  llint s = 0;
  for (int i = 0; i < N; ++i) {
    s += a[i];
    p.push_back({s, i});
  }

  llint sol = 1000000000000000000LL;
  auto sq = [](llint x) { return x * x; };

  for (int i = 0; i < ITER; ++i) {
    llint A = rand() % 1000 - 500;
    llint B = rand() % 1000 - 500;

    sort(p.begin(), p.end(), [A, B](pt a, pt b) {
      return A * (a.first - b.first) < B * (a.second - a.second);
    });

    for (int I = 0; I < p.size(); ++I) {
      for (int J = max(0, I - PS); J < I; ++J) {
        llint d = sq(p[I].first - p[J].first) + sq(p[I].second - p[J].second);
        sol = min(sol, d);
      }
    }
  }

  cout << sol << endl;

  return 0;
}