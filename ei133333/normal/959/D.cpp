#include <bits/stdc++.h>

using namespace std;


vector< bool > get_prime(int n) {
  vector< bool > prime(n + 1, true);

  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;

  for(int i = 2; i * i <= n; i++) {
    if(prime[i]) {
      for(int j = i + i; j <= n; j += i) prime[j] = false;
    }
  }

  return (prime);
}

int main() {
  int N, A[100000];
  cin >> N;

  auto table = get_prime(10000000);
  vector< int > primes;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  bool limited = false;
  bool used[10000001] = {};
  for(int i = 0; i < N; i++) {
    if(limited) {
      if(primes.empty()) {
        for(int j = 1; j < 10000001; j++) {
          if(!used[j] && table[j]) primes.emplace_back(j);
        }
        reverse(begin(primes), end(primes));
      }
      cout << primes.back() << " ";
      primes.pop_back();
    } else {
      for(int k = A[i];; k++) {
        int v = k;
        bool f = false;
        for(int j = 2; j * j <= v; j++) {
          if(v % j == 0) {
            if(used[j]) f = true;
            while(v % j == 0) v /= j;
          }
        }
        if(v > 1) if(used[v]) f = true;

        if(!f) {
          cout << k << " ";
          v = k;
          for(int j = 2; j * j <= v; j++) {
            if(v % j == 0) {
              used[j] = true;
              while(v % j == 0) v /= j;
            }
          }
          if(v > 1) used[v] = true;
          if(k != A[i]) limited = true;
          break;
        }
      }
    }
  }
  cout << endl;
}