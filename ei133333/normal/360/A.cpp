#include <bits/stdc++.h>

using namespace std;


const int INF = 1 << 30;

int main()
{
  int N, M;
  int A[5000], B[5000], C[5000], D[5000];

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    --B[i];
  }

  int S[5000], T[5000];
  fill_n(S, N, (int) 1e9);
  for(int i = M - 1; i >= 0; i--) {
    if(A[i] == 1) {
      for(int j = B[i]; j < C[i]; j++) {
        S[j] -= D[i];
      }
    } else {
      for(int j = B[i]; j < C[i]; j++) {
        S[j] = min(S[j], D[i]);
      }
    }
  }

  for(int i = 0; i < N; i++) {
    S[i] = min(S[i], (int) 1e9);
    T[i] = S[i];
  }

  for(int i = 0; i < M; i++) {
    if(A[i] == 1) {
      for(int j = B[i]; j < C[i]; j++) {
        S[j] += D[i];
      }
    } else {
      auto rmq = -INF;
      for(int j = B[i]; j < C[i]; j++) {
        rmq = max(rmq, S[j]);
      }
      if(rmq != D[i]) {
        cout << "NO" << endl;
        return (0);
      }
    }
  }

  cout << "YES" << endl;
  for(int i = 0; i < N; i++) {
    cout << T[i] << " ";
  }

}