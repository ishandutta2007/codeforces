#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{

  // (s_x + ... + s_y)(s_z + ... + s_t)

  int A;
  string S;

  cin >> A;
  cin >> S;

  map< int64, int > mp;
  for(int i = 0; i < S.size(); i++) {
    int sum = 0;
    for(int j = i; j >= 0; j--) {
      sum += S[j] - '0';
      ++mp[sum];
    }
  }


  int64 ret = 0;
  if(A > 0) {
    vector< int > divisor;
    for(int i = 1; i * i <= A; i++) {
      if(A % i != 0) continue;
      int j = A / i;
      if(i == j) ret += 1LL * mp[i] * mp[j];
      else ret += 1LL * mp[i] * mp[j] * 2;
    }
  } else {
    int64 latte = 0, malta = 0;
    for(auto& p : mp) latte += p.second;
    latte -= mp[0];
    malta += mp[0];
    ret += latte * malta * 2;
    ret += malta * malta;
  }
  cout << ret << endl;
}