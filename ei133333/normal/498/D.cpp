#include <bits/stdc++.h>

using namespace std;

int sz;
vector< int > seg[60];

int main()
{

  int N, A[100000];
  scanf("%d", &N);

  int sz = 1;
  while(sz < N) sz <<= 1;
  for(int i = 0; i < 60; i++) seg[i].assign(2 * sz - 1, 0);

  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    for(int j = 0; j < 60; j++) {
      seg[j][i + sz - 1] = 1;
      if(j % A[i] == 0) ++seg[j][i + sz - 1];
    }
  }
  for(int k = sz - 2; k >= 0; k--) {
    for(int i = 0; i < 60; i++) {
      seg[i][k] = seg[i][2 * k + 1] + seg[(i + seg[i][2 * k + 1]) % 60][2 * k + 2];
    }
  }

  function< int(int, int, int, int, int, int) > query = [&](int a, int b, int k, int l, int r, int mod)
  {
    if(a >= r || b <= l) return (0);
    if(a <= l && r <= b) return (seg[mod][k]);
    auto L = query(a, b, 2 * k + 1, l, (l + r) >> 1, mod);
    auto R = query(a, b, 2 * k + 2, (l + r) >> 1, r, (mod + L) % 60);
    return (L + R);
  };

  int Q;
  scanf("%d", &Q);
  while(Q--) {
    char a;
    int b, c;
    scanf(" %c %d %d", &a, &b, &c);
    if(a == 'A') {
      printf("%d\n", query(--b, --c, 0, 0, sz, 0));
    } else {
      --b;
      b += sz - 1;
      for(int j = 0; j < 60; j++) {
        seg[j][b] = 1;
        if(j % c == 0) ++seg[j][b];
      }
      while(b > 0) {
        b = (b - 1) >> 1;
        for(int i = 0; i < 60; i++) {
          seg[i][b] = seg[i][2 * b + 1] + seg[(i + seg[i][2 * b + 1]) % 60][2 * b + 2];
        }
      }
    }
  }
}