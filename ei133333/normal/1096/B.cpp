#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int mod = 998244353;

int main() {
  int N;
  string S;

  cin >> N;
  cin >> S;

  vector< int > latte(N), malta(N);
  int bit = 0;
  for(int i = 0; i < N; i++) {
    bit |= 1 << (S[i] - 'a');
    latte[i] = bit;
  }
  bit = 0;
  map< int, int > mp;
  for(int i = N - 1; i >= 0; i--) {
    bit |= 1 << (S[i] - 'a');
    malta[i] = bit;
    ++mp[malta[i]];
  }

  int64 ret = 1;
  for(int i = 0; i < 26; i++) {
    ret += mp[1 << i];
  }
  for(int i = 0; i < N; i++) {
    --mp[malta[i]];
    if(__builtin_popcount(latte[i]) == 1) {
      ret += mp[latte[i]];
      ret++;
    }
  }


  cout << ret % mod << endl;
}