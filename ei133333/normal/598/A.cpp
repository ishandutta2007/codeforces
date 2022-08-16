#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int K;
    cin >> K;
    int64 sum = 1LL * K * (K + 1) / 2;
    for(int64 i = 1; i <= K; i *= 2) sum -= i * 2;
    cout << sum << endl;
  }
}