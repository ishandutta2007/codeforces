#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 mod = 1e9 + 7;


int main() {
  int64 N, A[200000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int64 sum[200001][2] = {{}};
  for(int i = N - 1; i >= 0; i--) {
    sum[i][0] += sum[i + 1][1];
    sum[i][1] += sum[i + 1][0];
    sum[i][0] += A[i];
  }

  int ret = 0;
  int64 latte[2] = {};
  for(int i = 0; i < N; i++) {
    if(sum[i + 1][0] + latte[0] == sum[i + 1][1] + latte[1]) {
      ++ret;
    }
    latte[0] += A[i];
    swap(latte[0], latte[1]);
  }

  cout << ret << endl;
}