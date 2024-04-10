#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  string s, t;

  cin >> s >> t;

  int ns = s.size(), nt = t.size();
  
  vector<int> f(nt+1, 0);
  
  for (int i = 2; i <= nt; i++) {
    f[i] = f[i-1];
    while (f[i] > 0 && t[f[i]] != t[i-1])
      f[i] = f[f[i]];
    if (t[f[i]] == t[i-1])
      f[i]++;
  }

  vector<bool> end(ns, false);

  int have = 0;
  for (int i = 0; i < ns; i++) {
    while (have > 0 && t[have] != s[i])
      have = f[have];
    if (t[have] == s[i])
      have++;
    if (have == nt) {
      end[i] = true;
      have = f[have];
    }
  }

  const int mod = 1e9+7;
  vector<int> dp0(ns+1), dp1(ns+1), dp2(ns+1);

  dp0[0] = 1;
  dp1[0] = 0;
  dp2[0] = 1;
  for (int p = 1; p <= ns; p++) {
    if (end[p-1])
      dp1[p] = dp2[p - nt];
    else
      dp1[p] = dp1[p-1];

    dp0[p] = (dp0[p-1] + dp1[p]) % mod;

    dp2[p] = (dp2[p-1] + dp0[p]) % mod;
  }

  int ret = (dp0[ns] - 1 + mod) % mod;

  printf("%d\n", ret);

  return 0;
}