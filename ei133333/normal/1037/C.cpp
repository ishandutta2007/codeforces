#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  string A, B;
  cin >> N >> A >> B;
  int ret = 0;
  for(int i = 1; i < N; i++) {
    if(A[i] == B[i - 1] && A[i - 1] == B[i] && A[i] != A[i - 1]) {
      swap(A[i], A[i - 1]);
      ++ret;
    }
  }
  for(int i = 0; i < N; i++) {
    if(A[i] != B[i]) ++ret;
  }
  cout << ret << endl;
}