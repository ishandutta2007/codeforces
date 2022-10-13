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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;
    int minId = min_element(begin(a), end(a)) - begin(a);
    int maxId = max_element(begin(a), end(a)) - begin(a);
    cout << minId + 1 << ' ' << maxId + 1 << '\n';
  }
}