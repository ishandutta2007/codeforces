#include <bits/stdc++.h>
using namespace std;

int isGood(vector <int> b)
{
  for (int i = 1; i + 1 < b.size(); i++)
    if (b[i + 1] - b[i] != b[i] - b[i - 1])
      return 0;
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a[200200];
  cin >> n;
  map <int, int> id;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    id[a[i]] = i + 1;
  }

  sort(a, a + n);
  for (int removedId = 0; removedId < 2; removedId++)
  {
    vector <int> b;
    for (int i = 0; i < n; i++)
      if (i != removedId)
        b.push_back(a[i]);

    if (isGood(b))
    {
      cout << id[a[removedId]] << endl;
      return 0;
    }
  }

  int removedId = 0, last = a[1];
  for (int i = 2; i < n; i++)
    if (a[i] - last == a[1] - a[0]) last = a[i];
    else  
    {
      if (removedId)
      {
        cout << -1 << endl;
        return 0;
      }
      removedId = id[a[i]];
    }

  cout << removedId << endl;
}