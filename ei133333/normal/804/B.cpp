#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int mod = 1e9 + 7;

int main()
{
  int64 fact[1000001];
  fact[0] = 1;
  for(int i = 1; i <= 1000000; i++) {
    fact[i] = fact[i - 1] * 2;
    fact[i] %= mod;
  }

  string S;
  cin >> S;

  int64 ret = 0;
  int A_sz = 0;
  for(int j = 0; j < S.size(); j++) {
    if(S[j] == 'b') {
      ret += fact[A_sz];
      ret %= mod;
      ret += mod - 1;
      ret %= mod;
    } else {
      ++A_sz;
    }
  }
  cout << ret << endl;
}