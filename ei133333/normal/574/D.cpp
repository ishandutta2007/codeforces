#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N, H[100002] = {};
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> H[i];
  }
  for(int i = 0; i <= N; i++) {
    H[i] = min(H[i], H[i - 1] + 1);
  }
  int ret = 0;
  for(int i = N; i > 0; i--) {
    H[i] = min(H[i], H[i + 1] + 1);
    ret = max(ret, H[i]);
  }
  cout << ret << endl;
}