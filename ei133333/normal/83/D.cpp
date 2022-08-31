#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int >;


bool isprime(int x)
{
  for(int i = 2; i * i <= x; i++) {
    if(x % i == 0) return (false);
  }
  return (true);
}

int sz(int N, int K)
{
  if(N < K || !isprime(K)) return (0);
  if(1LL * K * K > N) return(1);
  N /= K;
  int ret = N;
  for(int i = 2; i < K; i++) ret -= sz(N, i);
  return (ret);
}

int main()
{
  int A, B, K;
  cin >> A >> B >> K;
  cout << sz(B, K) - sz(A-1, K) << endl;
}