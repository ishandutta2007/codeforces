#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;

int main()
{
  int64 N, K, M, T[45];

  cin >> N >> K >> M;
  for(int i = 0; i < K; i++) {
    cin >> T[i];
  }
  sort(T, T + K);

  vector< int64 > curr(2222, INF);
  curr[0] = 0;

  for(int i = 0; i < N; i++) {
    vector< int64 > next(curr);
    int64 sum = 0LL;

    for(int j = 0; j < K; j++) {
      int point = j + 1;
      if(j + 1 == K) ++point;
      sum += T[j];
      for(int k = 2221; k >= point; k--) {
        next[k] = min(next[k], curr[k - point] + sum);
      }
    }
    curr.swap(next);
  }

  for(int i = 2221; i >= 0; i--) {
    if(curr[i] <= M) {
      cout << i << endl;
      return (0);
    }
  }

}