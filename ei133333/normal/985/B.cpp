#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

// 

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  string A[2000];

  cin >> N >> M;

  int all[2000] = {};
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    for(int j = 0; j < M; j++) {
      if(A[i][j] == '1') ++all[j];
    }
  }

  for(int i = 0; i < N; i++) {
    bool f = true;
    for(int j = 0; j < M; j++) {
      if(A[i][j] == '1' && all[j] == 1) f = false;
    }
    if(f) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}