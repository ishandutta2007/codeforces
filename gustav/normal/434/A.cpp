#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXM 100005
#define MAXN 100005

int N, M;
int a[MAXM];

vector< int > p[MAXN];
vector< long long > s[MAXN];

long long cost(int x, int y) {
  int i = lower_bound(p[x].begin(), p[x].end(), y) - p[x].begin();

  long long sum = s[x].back() - 2LL * s[x][i];
  long long cnt = 2LL * i - p[x].size();

  return sum + cnt * y;
}

int main(void)
{
  scanf("%d%d", &N, &M);

  for (int i = 0; i < M; ++i)
    scanf("%d", a + i);

  long long tot = 0;

  for (int i = 0; i < M - 1; ++i) {
    if (a[i] != a[i + 1]) {
      p[a[i]].push_back(a[i + 1]);
      p[a[i + 1]].push_back(a[i]);
      tot += abs(a[i + 1] - a[i]);
    }
  }

  for (int i = 1; i <= N; ++i){
    sort(p[i].begin(), p[i].end());
    s[i].push_back(0);

    for (int j = 0; j < p[i].size(); ++j)
      s[i].push_back(s[i].back() + p[i][j]);
  }

  long long sol = tot;

  for (int i = 1; i <= N; ++i) {
    long long rest = tot - cost(i, i);

    int lo = 1, hi = N, mid;
    while (lo < hi) {
      mid = (lo + hi) / 2;
      if (cost(i, mid) < cost(i, mid + 1)) 
        hi = mid;
      else
        lo = mid + 1;
    }

    sol = min(sol, cost(i, lo) + rest);
  }

  cout << sol << endl;

  return 0;
}