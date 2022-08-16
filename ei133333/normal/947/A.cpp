#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

using int64 = long long;

map< int64, int > prime_factor(int64_t n) {
  map< int64, int > ret;
  for(int64 i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

int main() {
  int X2;
  cin >> X2;

  auto table = prime_factor(X2);
  int can[1000001] = {};

  for(auto &s : table) {
    auto l = max(s.first + 1LL, X2 - s.first + 1LL);
    auto r = X2;
    if(l <= r) {
      can[l]++;
      can[r + 1]--;
    }
  }
  for(int i = 1; i <= 1000000; i++) {
    can[i] += can[i - 1];
  }

  int64 ret = INF;
  for(int i = 0; i <= 1000000; i++) {
    if(can[i]) {
      for(auto &s : prime_factor(i)) {
        auto l = max(s.first + 1LL, i - s.first + 1LL);
        auto r = X2;
        if(l <= r) ret = min(ret, l);
      }
    }
  }

  cout << ret << endl;
}