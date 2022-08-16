#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

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

bool bit[200000001];
const int SHIFT = 100000000;

int main() {
  auto get = get_prime(20000);
  vector< int > primes;
  for(int i = 0; i < get.size(); i++) {
    if(get[i] == 1) primes.emplace_back(i);
  }

  int N, A[5000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(A[i] != 0) {
      for(auto &p : primes) {
        int fact = p * p;
        while(A[i] % fact == 0) A[i] /= fact;
      }
    }
  }

  vector< int > ans(N + 1);
  for(int i = 0; i < N; i++) {
    int sum = 0;
    for(int j = i; j < N; j++) {
      if(A[j] != 0 && !bit[A[j] + SHIFT]) {
        bit[A[j] + SHIFT] = true;
        ++sum;
      }
      ans[max(1, sum)]++;
    }
    for(int j = i; j < N; j++) {
      bit[A[j] + SHIFT] = false;
    }
  }


  for(int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;


}