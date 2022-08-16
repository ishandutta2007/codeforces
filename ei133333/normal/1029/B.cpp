#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[200000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  int ret = 1, pv = 1;
  for(int i = 1; i < N; i++) {
    if(A[i - 1] * 2 >= A[i]) {
      ++pv;
      ret = max(ret, pv);
    } else {
      pv = 1;
    }
  }
  cout << ret << endl;
}