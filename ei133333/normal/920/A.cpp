#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int T, N, K, X[200];

  cin >> T;
  while(T--) {
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
      cin >> X[i];
      --X[i];
    }
    for(int t = 1;; t++) {
      vector< int > used(N);
      for(int i = 0; i < K; i++) {
        for(int j = max(0, X[i] - t + 1); j <= min(N - 1, X[i] + t - 1); j++) {
          used[j] = 1;
        }
      }
      if(count(begin(used), end(used), 1) == N) {
        cout << t << endl;
        break;
      }
    }
  }
}