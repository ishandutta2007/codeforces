#include<bits/stdc++.h>

using namespace std;

template< class T >
struct CumulativeSum
{
  vector< T > data;

  CumulativeSum(int sz) : data(sz, 0) {};

  void add(int k, int x)
  {
    data[k] += x;
  }

  void build()
  {
    for(int i = 1; i < data.size(); i++) {
      data[i] += data[i - 1];
    }
  }

  T query(int k)
  {
    if(k < 0) return (0);
    return (data[min(k, (int) data.size() - 1)]);
  }
};

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

static int64 fact[404040], rfact[404040];


int main()
{
  fact[0] = rfact[0] = 1;
  for(int i = 1; i < 404040; i++) {
    fact[i] = fact[i - 1] * i % mod;
    rfact[i] = modInv(fact[i]);
  }

  string S;
  cin >> S;
  int N = (int) S.size();
  CumulativeSum< int > open(N), close(N);
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == '(') open.add(i, 1);
    else close.add(i, 1);
  }
  open.build();
  close.build();

  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    if(S[i] == '(') {
      int l = open.query(i), r = close.query(N) - close.query(i);
      (ret += fact[l + r - 1] % mod * rfact[l] % mod * rfact[r - 1] % mod) %= mod;
    }
  }

  cout << ret << endl;
}