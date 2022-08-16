#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int mod = 1e9 + 7;

inline int64 modPow(int64 x, int64 n)
{
  if(n == 0) return (1);
  int64 ret = modPow(x, n / 2);
  (ret *= ret) %= mod;
  if(n & 1) (ret *= x) %= mod;
  return (ret);
}

inline int64 modInv(int64 a)
{
  return (modPow(a, mod - 2));
}

inline int64 modCombination(int p, int q)
{
  static int64 fact[202020], rfact[202020];
  if(fact[0] == 0) {
    fact[0] = rfact[0] = 1;
    for(int i = 1; i < 202020; i++) {
      fact[i] = fact[i - 1] * i % mod;
      rfact[i] = modInv(fact[i]);
    }
  }
  if(q < 0 || p < q) return (0);
  return (fact[p] * rfact[q] % mod * rfact[p - q] % mod);
}

int main()
{
  int N, A[200000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  --N;

  int base = N / 4 * 4;
  int rest = N % 4;
  bool flip = false;
  while(rest > 0) {
    int B[200000];
    --N;
    --rest;
    for(int i = 0; i <= N; i++) {
      if(flip) (B[i] = A[i] - A[i + 1] + mod) %= mod;
      else (B[i] = A[i] + A[i + 1]) %= mod;
      flip ^= true;
    }
    swap(A, B);
  }


  int64 ret = 0;
  for(int i = 0; i <= N; i++) {
    (ret += modCombination(N % 2, i % 2) * modCombination(N / 2, i / 2) % mod * (A[i] + mod) % mod) %= mod;
  }
  cout << ret << endl;
}