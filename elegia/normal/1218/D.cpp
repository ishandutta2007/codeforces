#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010, P = 1000000007, L = 17;

int n;
int prt[N], pw[N];
int vis[N];
vector<pair<int, int>> e[N];
int able[1 << L], ways[1 << L];

int norm(int x) {
  return x >= P ? x - P : x;
}

void add(int& x, int y) {
  if ((x += y) >= P)
    x -= P;
}

void sub(int& x, int y) {
  if ((x -= y) < 0)
    x += P;
}

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    x = x * (ll)x % P;
    k >>= 1;
  }
  return ret;
}

void fwt(int* a) {
  for (int i = 0; i < L; ++i)
    for (int j = 0; j < (1 << L); ++j)
      if ((j >> i) & 1) {
        int tmp = a[j];
        a[j] = norm(a[j ^ (1 << i)] - a[j] + P);
        add(a[j ^ (1 << i)], tmp);
      }
}

void dfs(int u) {
  vis[u] = 1;
  for (const auto& pr : e[u]) {
    int v, w;
    tie(v, w) = pr;
    if (v == prt[u])
      continue;
    if (vis[v] == 1) {
      static int val[1 << L];
      memset(val, 0, sizeof(val));
      ++val[w];
      int x = u;
      while (x != v) {
        ++val[pw[x]];
        x = prt[x];
      }
      fwt(val);
      fwt(able);
      for (int i = 0; i < (1 << L); ++i)
        able[i] = able[i] * (ll)val[i] % P;
      for (int i = 0; i < (1 << L); ++i)
        ways[i] = ways[i] * (ll)val[i] % P;
      fwt(able);
      for (int i = 0; i < (1 << L); ++i)
        able[i] = bool(able[i]);
    } else if (vis[v] == 0) {
      prt[v] = u;
      pw[v] = w;
      dfs(v);
    }
  }
  vis[u] = -1;
}

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	int m, sum = 0;
	scanf("%d%d", &n, &m);
	while (m--) {
	  int u, v, w;
	  scanf("%d%d%d", &u, &v, &w);
	  sum ^= w;
	  e[u].emplace_back(v, w);
	  e[v].emplace_back(u, w);
	}
	able[sum] = 1;
	ways[sum] = 1;
  fwt(ways);
	dfs(1);
	fwt(ways);
	int nv = mpow(2, P - 1 - L);
	for (int i = 0; i < (1 << L); ++i)
	  if (able[i]) {
	    printf("%d %d\n", i, int(ways[i] * (ll)nv % P));
	    break;
	  }
	
  return 0;
}