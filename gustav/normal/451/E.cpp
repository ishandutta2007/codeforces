#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long llint;
const llint mod = 1000000007;

int n;
llint s;
llint f[22];

llint mult(llint a, llint b) { return (a * b) % mod; }
llint add(llint a, llint b) { return (a + b) % mod; }

llint inv(llint n) {
  llint ret = 1;
  for (int i = 0; (1LL << i) <= mod - 2; ++i) {
    if ((((mod - 2) >> i)& 1) == 1) 
      ret = mult(ret, n);
    n = mult(n, n);
  }
  return ret;
}

llint I[22];

llint ways(llint s, int n) {
  llint ret = 1;
  for (llint i = s + n - 1; i > s; --i) 
    ret = mult(ret, i % mod);
  for (llint i = n - 1; i >= 1; --i) 
    ret = mult(ret, I[i]);
  return ret;
}

int main(void)
{
  cin >> n >> s;
  for (int i = 0; i < n; ++i)
    cin >> f[i];
  
  for (int i = 1; i < n; ++i)
    I[i] = inv(i);

  llint sol = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    llint rem = 0;
    for (int i = 0; i < n; ++i)
      if (((mask >> i) & 1) == 1)
        rem += f[i] + 1;

    if (s - rem < 0) continue;

    int sgn = (__builtin_popcount(mask) % 2) ? -1 : +1;

    sol = add(sol, add(mod, sgn * ways(s - rem, n)));
  }

  cout << sol << endl;

  return 0;
}