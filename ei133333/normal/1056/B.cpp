#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, M;
  cin >> N >> M;

  vector< int64 > latte(M);
  for(int64 i = 0; i < M; i++) {
    //  M 
    int64 mod = (i * i) % M;
    latte[mod] += (N - i + M) / M;
  }
  latte[0]--;

  int64 ret = 0;
  for(int64 i = 0; i < M; i++) {
    for(int64 j = 0; j < M; j++) {
      if((i + j) % M == 0) {
        ret += 1LL * latte[i] * latte[j];
      }
    }
  }
  cout << ret << endl;
}