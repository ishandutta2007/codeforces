#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N;
  cin >> N;
  int ret = 0;
  while(N & 1) {
    vector< int64 > divisor;
    for(int64 i = 1; i * i <= N; i++) {
      if(N % i == 0) {
        divisor.emplace_back(i);
        if(i * i != N) divisor.emplace_back(N / i);
      }
    }
    sort(begin(divisor), end(divisor));
    for(auto &p : divisor) {
      if(p == 1) continue;
      N -= p;
      ++ret;
      break;
    }
  }
  cout << ret + N / 2 << endl;
}