#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;


int main() {
  int64 N, M, A[2000], B[2000], X;
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < M; i++) cin >> B[i];
  cin >> X;

  vector< int64 > smallest(M + 1, INF);
  smallest[0] = 0;
  for(int i = 0; i < M; i++) {
    int64 add = 0;
    for(int j = i; j < M; j++) {
      add += B[j];
      smallest[j - i + 1] = min(smallest[j - i + 1], add);
    }
  }
  for(int i = M - 1; i >= 0; i--) {
    smallest[i] = min(smallest[i], smallest[i + 1]);
  }

  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    int64 add = 0;
    for(int j = i; j < N; j++) {
      add += A[j];

      if(add <= X) {
        int64 ok = 0, ng = M + 1;
        while(ng - ok > 1) {
          int64 mid = (ok + ng) / 2;
          if(add * smallest[mid] <= X) ok = mid;
          else ng = mid;
        }
        ret = max(ret, 1LL * ok * (j - i + 1));
      }
    }
  }
  cout << ret << endl;
}