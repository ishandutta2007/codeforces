#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int BASE = 979983737;
const int P = 67;

int main()
{
  string s, pre, suf;
  cin >> s >> pre >> suf;
  int n = size(s);
  vector<int> isPre(n);
  for (int i = 0; i + size(pre) <= n; i++)
    isPre[i] = s.substr(i, size(pre)) == pre;
  vector<int> isSuf(n);
  for (int i = 0; i + size(suf) <= n; i++)
    isSuf[i] = s.substr(i, size(suf)) == suf;

  vector<long long> p = {1};
  for (int i = 1; i <= n; i++)
    p.push_back(p[i - 1] * P % BASE);
  vector<long long> h(n + 1);
  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p[i]) % BASE;

  int ans = 0;
  for (int len = max(size(pre), size(suf)); len <= n; len++)
  {
    set<long long> has;
    for (int i = 0; i + len <= n; i++)
      if (isPre[i] && isSuf[i + len - size(suf)])
      {
        long long curH = (h[i + len] - h[i] + BASE) % BASE * p[n - i] % BASE;
        has.insert(curH);
      }

    ans += size(has);
  }

  cout << ans << endl;
}