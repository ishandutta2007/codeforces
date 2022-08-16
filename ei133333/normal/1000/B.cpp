#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


int main() {
  int N, M, A[100003] = {};
  cin >> N >> M;
  ++N;
  for(int i = 1; i < N; i++) {
    cin >> A[i];
  }
  A[N++] = M;

  int sum[2][100003] = {{}};

  bool state = true;
  bool f[100003] = {};
  for(int i = N - 2; i >= 0; i--) {
    sum[state][i] += A[i + 1] - A[i];
    f[i] = state;
    state ^= 1;
  }
  for(int i = N - 2; i >= 0; i--) {
    sum[0][i] += sum[0][i + 1];
    sum[1][i] += sum[1][i + 1];
  }
  // true

  state = true;
  int all = 0, ret = 0;
  for(int i = 1; i < N; i++) {
    if(state) {
      all += A[i] - A[i - 1];
    }
    if(state) {
      all--;
      int tot = A[i] - 1;
      if(A[i - 1] < tot) {
        ret = max(ret, all + sum[0 ^ f[i]][i]);
      }
      all++;
    } else {
      int tot = A[i - 1] + 1;
      if(tot < A[i]) {

        all += A[i] - tot;
        ret = max(ret, all + sum[1 ^ f[i]][i]);
        all -= A[i] - tot;
      }
    }
    state ^= 1;
  }
  cout << max(ret, all) << endl;
}