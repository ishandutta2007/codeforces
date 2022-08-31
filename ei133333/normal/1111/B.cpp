#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, K, M, A[100000];
  cin >> N >> K >> M;
  int64 all = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    all += A[i];
  }
  sort(A, A + N);


  double ret = 0.0;
  for(int i = 0; i < N; i++) {
    if(M < 0) break;
    ret = max(ret, 1.0 * (all + min(1LL * (N - i) * K, M)) / (N - i));
    all -= A[i];
    --M;
  }

  cout << fixed << setprecision(10) << ret << endl;
}