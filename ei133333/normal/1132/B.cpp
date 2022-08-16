#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[300000];
  int M;
  cin >> N;
  int64 all = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    all += A[i];
  }
  sort(A, A + N);
  cin >> M;
  for(int i = 0; i < M; i++) {
    int Q;
    cin >> Q;
    cout << all - A[N - Q] << endl;
  }
}