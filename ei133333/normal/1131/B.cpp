#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[10001] = {}, B[10001] = {};
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i] >> B[i];
  }
  int ret = 1;
  for(int i = 1; i <= N; i++) {
    while(A[i - 1] < A[i] || B[i - 1] < B[i]) {
      bool f = A[i - 1] < A[i];
      bool g = B[i - 1] < B[i];
      if(f) {
        if(g) {
          if(A[i - 1] < B[i - 1]) ++A[i - 1];
          else ++B[i - 1];
        } else {
          ++A[i - 1];
        }
      } else {
        ++B[i - 1];
      }
      ret += A[i - 1] == B[i - 1];
    }
  }
  cout << ret << endl;
}