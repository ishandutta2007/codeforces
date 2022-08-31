#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[15];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(int i = 0; i < (1 << N); i++) {
    int v = 0;
    for(int j = 0; j < N; j++) {
      if((i >> j) & 1) v += A[j];
      else v += 360 - A[j];
      v %= 360;
    }
    if(v == 0) {
      cout << "YES\n";
      exit(0);
    }
  }

  cout << "NO\n";
  exit(0);

}