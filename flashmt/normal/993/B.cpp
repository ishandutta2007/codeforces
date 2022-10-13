#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<int> a(m), b(n);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    a[i] = 1 << x - 1 | 1 << y - 1;
  }
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    b[i] = 1 << x - 1 | 1 << y - 1;
  }

  set<int> knowMe;
  vector<set<int>> knowA(m), knowB(n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i] != b[j] && (a[i] & b[j]))
      {
        int x = __lg(a[i] & b[j]);
        knowA[i].insert(x);
        knowB[j].insert(x);
        knowMe.insert(x);
      }

  if (size(knowMe) == 1) cout << *knowMe.begin() + 1 << endl;
  else
  {
    int isGood = 1;
    for (int i = 0; i < m; i++)
      isGood &= size(knowA[i]) <= 1;
    for (int i = 0; i < n; i++)
      isGood &= size(knowB[i]) <= 1;
    cout << isGood - 1 << endl;
  }
}