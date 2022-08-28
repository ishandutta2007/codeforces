#include <cstdio>

#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#ifndef ONLINE_JUDGE

const int N = 110, V = 110;

#else

const int N = 100010, V = 7010;

#endif

int n, q;
int mu[N];
bitset<V> dv[V], col[V];
bitset<V> st[N];

int main() {
  for (int x = 1; x < V; ++x)
    for (int y = x; y < V; y += x)
      dv[y].set(x);
  mu[1] = 1;
  for (int x = 1; x < V; ++x) {
    if (mu[x]) {
      for (int y = 1; y * x < V; ++y)
        col[y].set(y * x);
    }
    for (int y = x + x; y < V; y += x)
      mu[y] -= mu[x];
  }

  scanf("%d%d", &n, &q);
  while (q--) {
    int t, x, y, z;
    scanf("%d%d%d", &t, &x, &y);
    switch (t) {
    case 1:
      st[x] = dv[y];
      break;
    case 2:
      scanf("%d", &z);
      st[x] = st[y] ^ st[z];
      break;
    case 3:
      scanf("%d", &z);
      st[x] = st[y] & st[z];
      break;
    case 4:
      putchar('0' + ((col[y] & st[x]).count() & 1));
      break;
    }
  }

  return 0;
}