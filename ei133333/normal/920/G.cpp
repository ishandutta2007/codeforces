#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

vector< int > prime_factor(int n)
{
  vector< int > primes;
  for(int i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      primes.emplace_back(i);
      while(n % i == 0) n /= i;
    }
  }
  if(n != 1) primes.emplace_back(n);
  return (primes);
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int X, P, K;
    cin >> X >> P >> K;

    auto ps = prime_factor(P);

    auto check = [&](int x)
    {
      int64 ret = 0;
      for(int i = 0; i < (1 << ps.size()); i++) {
        int64 sum = 0, factor = 1;
        for(int j = 0; j < ps.size(); j++) {
          if(i & (1 << j)) factor *= ps[j];
        }
        if(__builtin_popcount(i) % 2 == 0) ret += x / factor;
        else ret -= x / factor;
      }
      return(ret);
    };

    int ok = 10000000, ng = X;
    auto pre_count = check(X);
    while(ok - ng > 1) {
      int mid = (ok + ng) / 2;
      if(check(mid) - pre_count >= K) ok = mid;
      else ng = mid;
    }
    cout << ok << endl;
  }
}