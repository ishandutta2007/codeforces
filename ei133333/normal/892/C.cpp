#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N, A[2000];
  cin >> N;
  bool ex = false;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    ex |= A[i] == 1;
  }

  if(ex) {
    int add = N;
    for(int i = 0; i < N; i++) {
      add -= A[i] == 1;
    }
    cout << add << endl;
    return 0;
  }


  int len = INF;
  for(int i = 0; i < N; i++) {
    int v = 0;
    for(int j = i; j < N; j++) {
      v = __gcd(A[j], v);
      if(v == 1) {
        len = min(len, j - i + 1);
        break;
      }
    }
  }

  if(len == INF) cout << -1 << endl;
  else cout << len + N - 2 << endl;
}