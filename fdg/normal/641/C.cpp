#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

// vector<int> v;

// void go(int t, int x = 0) {
//   if (t == 1) {
//     vector<int> nv = v;
//     for (int i = 0; i < v.size(); ++i) {
//       v[(i + x + 2LL * v.size()) % v.size()] = nv[i];
//     }
//   } else {
//     for (int i = 0; i < v.size(); i += 2)
//       swap(v[i], v[i + 1]);
//   }
// }

int sgn(int x) {
  return (x > 0) - (x < 0);
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  // for (int i = 1; i <= n; ++i)
  //   v.push_back(i);

  int N = n / 2;
  int tp[2] = {0, 1}, sh[2] = {0};
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      // go(1, x);
      if (x % 2 == 0) {
        x /= 2;
        sh[0] = (sh[0] - x % N + 5 * N) % N;
        sh[1] = (sh[1] - x % N + 5 * N) % N;
      } else {
        int sg = sgn(x);
        x /= 2;
        sh[0] = (sh[0] - x % N - (sg <= 0 ? sg : 0) + 5 * N) % N;
        sh[1] = (sh[1] - x % N - (sg >= 0 ? sg : 0) + 5 * N) % N;
        swap(tp[0], tp[1]);
        swap(sh[0], sh[1]);
      }
    } else {
      // go(2);
      swap(tp[0], tp[1]);
      swap(sh[0], sh[1]);
    }
  }
  // cout << tp[0] << "  " << sh[0] << endl;
  // cout << tp[1] << "  " << sh[1] << endl;
  for (int i = 0; i < n; i += 2) {
    {
      int x = 2 * ((sh[0] + i / 2) % N) + (tp[0] == 0 ? 1 : 2);
      printf("%d ", x);
    }
    {
      int x = 2 * ((sh[1] + i / 2) % N) + (tp[1] == 0 ? 1 : 2);
      printf("%d ", x);
    }
  }
  printf("\n");
  // for (int x : v)
  //   printf("%d ", x);
  // printf("\n");
  return 0;
}