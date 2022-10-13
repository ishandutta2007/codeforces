#include <bits/stdc++.h>
using namespace std;
const int ANS[] = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q, a;
  cin >> q;
  while (q--)
  {
    cin >> a;
    for (int i = 2; i <= 25; i++)
      if (a <= (1 << i) - 1)
      {
        if (a == (1 << i) - 1) cout << ANS[i - 2] << '\n';
        else cout << (1 << i) - 1 << '\n';
        break;
      }
  }
}