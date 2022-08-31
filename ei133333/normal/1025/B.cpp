#include<bits/stdc++.h>

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

  int N, A[150000], B[150000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  auto latte = prime_factor(A[0]);
  auto malta = prime_factor(B[0]);

  for(auto &x : latte) {
    bool f = true;
    for(int j = 0; j < N; j++) {
      f &= A[j] % x.first == 0 || B[j] % x.first == 0;
    }
    if(f) {
      cout << x.first << endl;
      return 0;
    }
  }

  for(auto &x : malta) {
    bool f = true;
    for(int j = 0; j < N; j++) {
      f &= A[j] % x.first == 0 || B[j] % x.first == 0;
    }
    if(f) {
      cout << x.first << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}