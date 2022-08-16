#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;


int main() {
  int N, Q, L[5000], R[5000];
  cin >> N >> Q;
  for(int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i];
    --L[i];
  }
  int ret = INF;
  for(int i = 0; i < Q; i++) {
    vector< int > add(N + 1);
    for(int j = 0; j < Q; j++) {
      if(i == j) continue;
      add[L[j]]++;
      add[R[j]]--;
    }
    for(int j = 1; j <= N; j++) {
      add[j] += add[j - 1];
    }
    vector< int > range(N + 1);
    int tap = 0;
    for(int j = 0; j < N; j++) {
      if(add[j] == 0) ++tap;
      if(add[j] == 1) range[j + 1] = 1;
    }
    for(int j = 1; j <= N; j++) {
      range[j] += range[j - 1];
    }
    int ris = INF;
    for(int j = 0; j < Q; j++) {
      if(i == j) continue;
      ris = min(ris, range[R[j]] - range[L[j]]);
    }
    ret = min(ret, tap + ris);
  }
  cout << N - ret << endl;
}