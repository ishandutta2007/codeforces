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
    vector<long long> a(n);
    map<long long, int> need;
    long long sumA = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      sumA += a[i];
      need[a[i]]++;
    }

    queue<long long> q;
    q.push(sumA);
    int cut = 0;
    while (!empty(q) && cut <= n - 1)
    {
      auto x = q.front();
      q.pop();

      if (need.count(x))
      {
        need[x]--;
        if (!need[x])
          need.erase(x);
        continue;
      }

      q.push(x / 2);
      q.push(x - x / 2);
      cut++;
    }

    cout << (cut == n - 1 && empty(need) ? "YES" : "NO") << '\n';
  }
}