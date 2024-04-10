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
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];

    int sId = -1;
    for (int i = 1; i < n; i++)
      if (p[i] < p[0])
      {
        sId = i;
        break;
      }

    int found = 0;
    if (sId >= 0)
    {
      int bId = -1;
      for (int i = sId * 2 + 1; i < n; i++)
        if (p[i] < p[i - 1])
        {
          bId = i;
          break;
        }

      if (bId >= 0)
        for (int i = n / 2; i > bId; i--)
          if (p[i] < p[i - 1] && (i - bId) > sId)
          {
            cout << sId << ' ' << bId - sId << ' ' << i - bId << '\n';
            found = 1;
            break;
          }
    }

    if (!found)
      cout << "0 0 0\n";
  }
}