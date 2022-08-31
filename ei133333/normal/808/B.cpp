#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, K, A[200000];
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];

  int64 ret = 0, sum = 0;
  for(int i = 0; i < K - 1; i++) {
    sum += A[i];
  }
  for(int i = K - 1; i < N; i++) {
    sum += A[i];
    ret += sum;
    sum -= A[i - (K - 1)];
  }
  cout << fixed << setprecision(10) << 1.0 * ret / (N - K + 1) << endl;
}