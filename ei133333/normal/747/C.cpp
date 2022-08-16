#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, Q;
  int server[100] = {};

  cin >> N >> Q;
  for(int i = 0; i < Q; i++) {
    int T, K, D;
    cin >> T >> K >> D;

    vector< int > isok;
    int sum = 0;
    for(int j = 0; j < N; j++) {
      if(server[j] <= T) {
        isok.push_back(j);
        sum += j + 1;
        if(isok.size() == K) break;
      }
    }
    if(isok.size() < K) {
      cout << -1 << endl;
    } else {
      cout << sum << endl;
      for(int j = 0; j < K; j++) {
        server[isok[j]] = T + D;
      }
    }
  }
}