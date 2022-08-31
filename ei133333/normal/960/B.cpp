#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, X, Y, A[1000], B[1000];
  cin >> N >> X >> Y;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  for(int i = 0; X > 0 || Y > 0; i++) {
    int64 best1 = 0, best2 = 0;
    for(int j = 0; j < N; j++) best1 = max(best1, llabs(B[j] - A[j]));
    for(int j = 0; j < N; j++) best2 = max(best2, llabs(B[j] - A[j]));

    if((best1 > best2 && X > 0) || (Y == 0)) {
      for(int j = 0; j < N; j++) {
        if(llabs(B[j] - A[j]) == best1) {
          if(B[j] > A[j]) ++A[j];
          else --A[j];
          break;
        }
      }
      --X;
    } else {
      for(int j = 0; j < N; j++) {
        if(llabs(A[j] - B[j]) == best2) {
          if(A[j] > B[j]) ++B[j];
          else --B[j];
          break;
        }
      }
      --Y;
    }
  }
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    ret += 1LL * (B[i] - A[i]) * (B[i] - A[i]);
  }
  cout << ret << endl;
}