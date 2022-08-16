#include <bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 1e9 + 7;


int main()
{
  int N;
  string S[5000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  vector< int > dp1(5001), dp2(5001);
  if(S[0] == "f") dp1[1] = 1;
  else dp2[0] = 1;


  for(int i = 1; i < N; i++) {

    vector< int > dp3(5001), dp4(5001);

    if(S[i] == "f") {
      int sum = 0;
      for(int j = 5000; j >= 0; j--) {
        if(j < 5000) (dp3[j + 1] += dp1[j]) %= mod;
        (sum += dp2[j]) %= mod;
        (dp3[j + 1] += sum) %= mod;
      }
    } else {
      int sum = 0;
      for(int j = 5000; j >= 0; j--) {
        (dp4[j] += dp1[j]) %= mod;
        (sum += dp2[j]) %= mod;
        (dp4[j] += sum) %= mod;
      }
    }
    dp1.swap(dp3);
    dp2.swap(dp4);
  }

  cout << (accumulate(begin(dp1), end(dp1), 0LL) + accumulate(begin(dp2), end(dp2), 0LL)) % mod << endl;
}