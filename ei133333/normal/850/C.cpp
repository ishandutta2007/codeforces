#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 mask = (1LL << 31) - 1;

map< int64, int > dp;

int rec(int64 bit)
{
  if(bit == 0) return (0);
  if(dp.count(bit)) return (dp[bit]);
  set< int > grundy;
  int highest = 0;
  for(int64 i = 30; i >= 0; i--) {
    if((bit >> i)& 1) {
      highest = i;
      break;
    }
  }
  for(int64 i = 0; i <= highest; i++) {
    grundy.emplace(rec(bit & ~(mask << i) | (bit >> (i + 1))));
  }
  int med = 0;
  while(grundy.count(med)) ++med;
  return (dp[bit] = med);
}

typedef long long int64;

map< int64, int > prime_factor(int64 n)
{
  map< int64, int > ret;
  for(int64 i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

int main()
{
  int N, A[100];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  map< int, int > mult;
  for(int i = 0; i < N; i++) {
    auto p = prime_factor(A[i]);
    for(auto &s : p) mult[s.first] |= 1 << (s.second - 1);
  }

  int nim = 0;
  for(auto &s : mult) nim ^= rec(s.second);
  if(nim == 0) cout << "Arpa" << endl;
  else cout << "Mojtaba" << endl;

}