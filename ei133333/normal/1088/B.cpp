#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K;
  cin >> N >> K;
  vector< int > A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(begin(A), end(A));
  A.erase(unique(begin(A), end(A)), end(A));
  int base = 0;
  for(int i = 0; i < min(K, (int)A.size()); i++) {
    cout << A[i] - base << endl;
    base = A[i];
  }
  for(int i = A.size(); i < K; i++) {
    cout << 0 << endl;
  }
}