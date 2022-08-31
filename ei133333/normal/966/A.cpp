#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M, Cl, Ce, V, Q;
  scanf("%d %d %d %d %d", &N, &M, &Cl, &Ce, &V);
  vector< int > L(Cl), E(Ce);
  for(int i = 0; i < Cl; i++) scanf("%d", &L[i]);
  for(int i = 0; i < Ce; i++) scanf("%d", &E[i]);
  scanf("%d", &Q);
  while(Q--) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    if(y1 > y2) swap(y1, y2);
    if(x1 > x2) swap(x1, x2);

    int ret = 1 << 30;
    {
      auto x = lower_bound(E.begin(), E.end(), x1) - begin(E);
      if(x < E.size()) {
        if(E[x] <= x2) ret = min(ret, x2 - x1 + (y2 - y1 + V - 1) / V);
        else ret = min(ret, E[x] - x1 + E[x] - x2 + (y2 - y1 + V - 1) / V);
      }
      --x;
      if(x >= 0) {
        ret = min(ret, x1 - E[x] + x2 - E[x] + (y2 - y1 + V - 1) / V);
      }
    }


    {
      auto x = lower_bound(L.begin(), L.end(), x1) - begin(L);
      if(x < L.size()) {
        if(L[x] <= x2) ret = min(ret, x2 - x1 + (y2 - y1));
        else ret = min(ret, L[x] - x1 + L[x] - x2 + (y2 - y1));
      }
      --x;
      if(x >= 0) {
        ret = min(ret, x1 - L[x] + x2 - L[x] + (y2 - y1));
      }
    }

    if(y1 == y2) ret = min(ret, x2 - x1);
    printf("%d\n", ret);
  }

}