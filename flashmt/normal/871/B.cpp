#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int ask(int i, int j)
{
  cout << "? " << i << ' ' << j << endl;
  cout.flush();
  int resp;
  cin >> resp;
  return resp;
}

int main()
{
  int n;
  cin >> n;
  vector<int> f(n); // f(i) = p(0) ^ b(i)
  for (int i = 0; i < n; i++)
    f[i] = ask(0, i);
  vector<int> g(n); // g(i) = p(i) ^ b(0)
  g[0] = f[0];
  for (int i = 1; i < n; i++)
    g[i] = ask(i, 0);

  vector<int> p(n), b(n);
  vector<int> ans;
  int cntAns = 0;
  for (p[0] = 0; p[0] < n; p[0]++)
  {
    b[0] = f[0] ^ p[0];
    for (int i = 1; i < n; i++)
    {
      p[i] = g[i] ^ b[0];
      b[i] = f[i] ^ p[0];
    }

    int isGood = 1;
    for (int i = 0; i < n; i++)
      isGood &= p[b[i]] == i;

    if (isGood)
    {
      cntAns++;
      ans = p;
    }
  }

  cout << "!" << endl;
  cout << cntAns << endl;
  for (int x : ans)
    cout << x << ' ';
  cout << endl;
  cout.flush();
}