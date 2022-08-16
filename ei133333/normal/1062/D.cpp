#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 mod = 1e9 + 7;


int main() {
  int N;
  cin >> N;
  int64 ret = 0;
  for(int k = 1; k <= N; k++) {
    ret += 1LL * k * ((N - k) / k);
  }
  ret -= N-1;
  cout << ret*4 << endl;
}