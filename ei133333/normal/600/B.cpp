#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M, A[200000], B[200000];
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  for(int i = 0; i < M; i++) {
    int k;
    cin >> k;
    cout << (upper_bound(A, A + N, k) - A) << " ";
  }
  cout << endl;
}