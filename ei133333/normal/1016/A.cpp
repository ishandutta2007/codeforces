#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, M, A[200000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int64 mergin = 0;
  for(int i = 0; i < N; i++) {
    cout << (A[i] + mergin) / M << " ";
    mergin = (A[i] + mergin) % M;
  }
  cout << endl;
}