#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100000];
  cin >> N;
  int mx = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }
  int ret = 0, cnt = 0;
  for(int i = 0; i < N; i++) {
    if(mx == A[i]) {
      ++cnt;
      ret = max(ret, cnt);
    } else {
      cnt = 0;
    }
  }
  cout << ret << endl;
}