#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

int main() {
  int N;
  cin >> N;
  auto ret = prime_factor(N);


  int res = 0, mul = 1, add = 0;
  for(auto &p : ret) {
    mul *= p.first;
    for(int j = 0; j <= 30; j++) {
      if(p.second <= (1<<j)) {
        res = max(res, j);
        break;
      }
    }
  }
  for(auto& p : ret) {
    if(p.second != (1 << res)) add = true;
  }

  cout << mul << " " << res+add << endl;
}