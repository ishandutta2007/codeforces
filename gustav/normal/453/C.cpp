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

int n, m;
int u, v;

int x[MAXN];
int uf[MAXN];
vector< int > G[MAXN];

int find(int n) { return uf[n] == n ? n : uf[n] = find(uf[n]); }

vector< int > sol;

void go(int n, int dad = -1) {
  x[n] ^= 1;

  sol.pb(n);

  for (auto c : G[n]) {
    if (c == dad) continue;
    go(c, n);
    sol.pb(n); x[n] ^= 1;
    if (x[c]) {
      sol.pb(c); x[c] ^= 1;
      sol.pb(n); x[n] ^= 1;
    }
  }

  if (dad == -1 && x[n]) {
    sol.erase(sol.begin());
    x[n] ^= 1;
  }
}

int main(void)
{ 
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i)
    uf[i] = i;

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v); --u; --v;
    if (find(u) == find(v)) continue;
    uf[find(u)] = find(v);
    G[u].pb(v);
    G[v].pb(u);
  }

  for (int i = 0; i < n; ++i) 
    scanf("%d", x + i);

  for (int i = 0; i < n; ++i) {
    if (x[i]) {
      go(i);
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (x[i]) {
      puts("-1");
      return 0;
    }
  }

  printf("%d\n", sol.size());

  for (int i = 0; i < sol.size(); ++i)
    printf("%d ", sol[i] + 1);
  puts("");

  return 0;
}