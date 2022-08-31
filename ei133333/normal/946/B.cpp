#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

void f(int64& N, int64& M) {
  if(N == 0 || M == 0) {
    return;
  }
  if(N >= 2 * M) {
    N -= N / (2 * M) * (2 * M);
    return f(N, M);
  }
  if(M >= 2 * N) {
    M -= M / (2 * N) * (2 * N);
    return f(N, M);
  }
}

int main() {
  int64 N, M;
  cin >> N >> M;
  f(N, M);
  cout << N << " " << M << endl;
}