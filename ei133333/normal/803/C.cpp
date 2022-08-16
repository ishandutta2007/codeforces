#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, K;
  cin >> N >> K;

  int64 sum = 0;
  for(int i = 1; i <= K; i++) {
    sum += i;
    if(sum > N) {
      cout << -1 << endl;
      return (0);
    }
  }

  vector< int64 > vs;
  for(int64 i = 1; i * i <= N; i++) {
    if(N % i == 0) {
      vs.push_back(i);
      if(i * i != N) vs.push_back(N / i);
    }
  }
  sort(begin(vs), end(vs));
  reverse(begin(vs), end(vs));

  for(auto &v : vs) {
    int64 gcd = v;
    int64 space = N / gcd;
    if(K * (K + 1) / 2 <= space) {
      int64 sums = 0;
      for(int i = 1; i < K; i++) {
        sums += gcd * i;
        cout << gcd * i << " ";
      }
      cout << N-sums << endl;
      return (0);
    }
  }
}