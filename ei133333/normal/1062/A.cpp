#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[102];
  cin >> N;
  A[0] = 0;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  A[++N] = 1001;

  int ret = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j <= N; j++) {
      if(A[j] - A[i] == j - i) {
        ret = max(ret, j - i - 1);
      }
    }
  }
  cout << ret << endl;
}