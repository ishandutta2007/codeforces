#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, S, A[1000], B[1000];
  cin >> N >> S;
  --S;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  if(A[0] == 0) {
    cout << "NO\n";
    return 0;
  }
  if(A[S] == 1) {
    cout << "YES\n";
    return 0;
  }

  for(int i = S + 1; i < N; i++) {
    if(A[i] == 1 && B[i] == 1 && B[S] == 1) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
}