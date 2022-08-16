#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, M, K, A[200000];
  cin >> N >> M >> K;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  int64 p = A[N - 1], q = A[N - 2];

  int64 ret = 0;

  int64 skip = M / (K + 1);
  ret += skip * p * K;
  ret += skip * q;

  M -= skip * (K + 1);

  ret += M * p;

  cout << ret << endl;
}