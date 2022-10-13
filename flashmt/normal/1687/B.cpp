#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  for (int i = 0; i < m; i++)
  {
    string s(m, '0');
    s[i] = '1';
    cout << "? " << s << endl;
    cout.flush();
    cin >> l[i];
  }

  vector<int> id(m);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int u, int v) { return l[u] < l[v]; });
  string s(m, '0');
  int last = 0, ans = 0;
  for (int i : id)
  {
    s[i] = '1';
    cout << "? " << s << endl;
    cout.flush();
    int cur;
    cin >> cur;
    if (cur == last + l[i])
      ans += l[i];
    last = cur;
  }

  cout << "! " << ans << endl;
  cout.flush();
}