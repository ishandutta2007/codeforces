#include <bits/stdc++.h>

using namespace std;


const int mod = 1e9 + 7;

int main() {
  int N, Q, A[100000];
  vector< pair< int, int > > ev[100000];
  int ans[100000] = {};

  scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for(int i = 0; i < Q; i++) {
    int l, x;
    scanf("%d %d", &l, &x);
    ev[--l].emplace_back(x, i);
  }

  int res = 1;
  int flag[21] = {};
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 20; j++) {
      if((A[i] >> j) & 1) A[i] ^= flag[j];
    }
    if(A[i] == 0) {
      (res += res) %= mod;
    } else {
      for(int j = 0; j < 20; j++) {
        if((A[i] >> j) & 1) {
          flag[j] = A[i];
          break;
        }
      }
    }

    for(auto &e : ev[i]) {
      for(int j = 0; j < 20; j++) {
        if((e.first >> j) & 1) e.first ^= flag[j];
      }
      if(e.first == 0) ans[e.second] = res;
    }
  }

  for(int i = 0; i < Q; i++) {
    printf("%d\n", ans[i]);
  }
}