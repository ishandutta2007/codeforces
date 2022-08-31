#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

int main() {
  int N, A[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    --A[i];
  }
  auto match = [&](int idx, int v) {
    return A[idx] < 0 || A[idx] == v;
  };
  vector< int > high(200), any(200);
  for(int i = 0; i < 200; i++) {
    high[i] = match(0, i);
  }
  for(int i = 1; i < N; i++) {
    vector< int > high2(200), any2(200);
    int add = 0;
    for(int k = 0; k < 200; k++) {
      if(match(i, k)) {
        (high2[k] += add) %= mod;
        (any2[k] += high[k]) %= mod;
      }
      (add += high[k]) %= mod;
    }
    add = 0;
    for(int k = 199; k >= 0; k--) {
      (add += any[k]) %= mod;
      if(match(i, k)) {
        (any2[k] += add) %= mod;
      }
    }
    add = 0;
    for(int k = 0; k < 200; k++) {
      if(match(i, k)) {
        (high2[k] += add) %= mod;
      }
      (add += any[k]) %= mod;
    }
    any.swap(any2);
    high.swap(high2);
  }
  cout << accumulate(begin(any), end(any), 0LL) % mod << endl;
}