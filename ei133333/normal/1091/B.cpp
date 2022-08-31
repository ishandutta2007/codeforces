#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, X[1000], Y[1000], A[1000], B[1000];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
  for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

  sort(X, X + N);
  sort(Y, Y + N);
  sort(A, A + N);
  sort(B, B + N);
  cout << X[0] + A[N-1] << " " << Y[0] + B[N-1] << endl;
}