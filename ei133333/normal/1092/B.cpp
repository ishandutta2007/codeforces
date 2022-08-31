#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  int ret = 0;
  for(int i = 0; i < N; i += 2) ret += A[i + 1] - A[i];
  cout << ret << endl;
}