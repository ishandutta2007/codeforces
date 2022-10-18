#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back
#define MAXN 100005
#define MAXLG 18

int n, m, a, b;
llint x[MAXN];
llint y[MAXN];

int dep[MAXN];
int anc[MAXN][MAXLG];

deque< int > stk;

llint ccw(int a, int b, int c) {
  return x[a] * (y[b] - y[c]) + x[b] * (y[c] - y[a]) + x[c] * (y[a] - y[b]);
}

int lca(int a, int b) {
  if (dep[a] < dep[b])
    swap(a, b);

  for (int i = MAXLG - 1; i >= 0; --i) 
    if (dep[anc[a][i]] >= dep[b]) 
      a = anc[a][i];

  if (a == b) return a;

  for (int i = MAXLG - 1; i >= 0; --i) {
    if (anc[a][i] != anc[b][i]) {
      a = anc[a][i];
      b = anc[b][i];
    }
  }

  return anc[a][0];
}

bool slope(int a, int b, int i) {
  return (y[a] - y[i]) * (x[b] - x[i]) > (y[b] - y[i]) * (x[a] - x[i]);
}

int main(void)
{
  cin >> n;
  for (int i = 0; i < n; ++i) 
    cin >> x[i] >> y[i];
  
  for (int i = n - 1; i >= 0; --i) {
    int best = -1;

    while (stk.size() >= 2 && ccw(i, stk[0], stk[1]) >= 0) {
      if (best == -1 || slope(stk.front(), best, i))
        best = stk.front();
      stk.pop_front();
    }

    if (!stk.empty() && (best == -1 || slope(stk.front(), best, i)))
      best = stk.front();

    if (best == -1) 
      best = i;

    anc[i][0] = best;
    dep[i] = dep[best] + 1;

    stk.push_front(i);
  }

  for (int lg = 1; lg < MAXLG; ++lg) 
    for (int i = 0; i < n; ++i)
      anc[i][lg] = anc[anc[i][lg - 1]][lg - 1];

  scanf("%d", &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b); --a; --b;
    printf("%d ", lca(a, b) + 1);
  }
  puts("");

  return 0;
}