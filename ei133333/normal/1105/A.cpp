#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int main() {
  int N, A[1000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  int64 ret = INF, pos = -1;
  for(int t = 1; t <= 100; t++) {
    int64 add = 0;
    for(int j = 0; j < N; j++) {
      add += min(min(abs(A[j] - t), abs(A[j] - (t - 1))), abs(A[j] - (t + 1)));
    }
    if(ret > add) {
      ret = add;
      pos = t;
    }
  }
  cout << pos << " " << ret << endl;
}