#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[2], X[100][2];
  cin >> N >> A[0] >> A[1];
  if(A[0] > A[1]) swap(A[0], A[1]);
  for(int i = 0; i < N; i++) {
    cin >> X[i][0] >> X[i][1];
    if(X[i][0] > X[i][1]) swap(X[i][0], X[i][1]);
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      do {
        do {
          do {
            if(X[i][0] + X[j][0] <= A[0] && max(X[i][1], X[j][1]) <= A[1]) {
              ret = max(ret, X[i][0] * X[i][1] + X[j][0] * X[j][1]);
            }
          } while(next_permutation(A, A + 2));
        } while(next_permutation(X[j], X[j] + 2));
      } while(next_permutation(X[i], X[i] + 2));
    }
  }

  cout << ret << endl;
}