#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  cout << min(A[N-1]-A[1],A[N-2]-A[0]) << endl;
}