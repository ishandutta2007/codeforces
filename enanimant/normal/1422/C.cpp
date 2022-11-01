// October 4, 2020
//

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1422C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1422C.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  string s;
  cin >> s;
  int n = (int) s.size();
  long long ans = 0;
  long long sum = 0;
  long long p = 1;
  for (int i = 0; i < n; i++) {
    int d = s[n - 1 - i] - '0';
    long long m = n - i;
    long long coeff = m * (m - 1) / 2 % MOD * p % MOD + sum;
    ans = (ans + coeff * d) % MOD;
    sum = (sum + p * (i + 1)) % MOD;
    p = p * 10 % MOD;
  }
  cout << ans << '\n';


  return 0;
}