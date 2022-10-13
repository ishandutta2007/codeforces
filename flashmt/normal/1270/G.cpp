#include <bits/stdc++.h>
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
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a.push_back(i - x);
    }

    vector<int> flag(n, -1), cycle;
    int start = -1;
    for (int i = 0, x = 0;; i++)
      if (flag[x] >= 0)
      {
        start = flag[x];
        break;
      }
      else
      {
        flag[x] = i;
        cycle.push_back(x);
        x = a[x];
      }

    cout << cycle.size() - start << '\n';
    for (int i = start; i < cycle.size(); i++)
      cout << cycle[i] + 1 << " \n"[i == cycle.size() - 1];
  }
}