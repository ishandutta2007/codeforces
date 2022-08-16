#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int64 tousa(int64 a, int64 d, int64 n) {
  return (2 * a + (n - 1) * d) * n / 2;
}

int main() {
  int64 N;
  cin >> N;

  vector< int64 > divisor;
  for(int64 i = 1; i * i <= N; i++) {
    if(N % i == 0) {
      divisor.emplace_back(i);
      if(i * i != N) divisor.emplace_back(N / i);
    }
  }

  int64 ret = 0;
  set< int64 > uku;
  for(auto &p : divisor) {
    uku.emplace(tousa(1, p, N / p));
  }
  for(auto &p : uku) {
    cout << p << " ";
  }
  cout << endl;

}