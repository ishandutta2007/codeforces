#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> r(m), w(m);
    for (int i = 0; i < m; i++)
      cin >> r[i] >> w[i];
    int maxR = *max_element(begin(r), end(r));
    int maxW = *max_element(begin(w), end(w));
    if (maxR + maxW > n) cout << "IMPOSSIBLE" << endl;
    else
    {
      for (int i = 0; i < n; i++)
        cout << (i < maxR ? "R" : "W");
      cout << endl;
    }
  }
}