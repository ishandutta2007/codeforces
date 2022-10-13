#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), id(n + 1, -1);
  for (int i = 1; i < n; i++)
  {
    cout << '?';
    for (int j = 0; j < n - 1; j++)
      cout << ' ' << i;
    cout << ' ' << n << endl;
    cout.flush();
    int resp;
    cin >> resp;
    if (resp)
    {
      a[resp - 1] = n;
      a[n - 1] = i;
      id[n] = resp - 1;
      id[i] = n - 1;
      break;
    }
  }

  if (id[n] < 0)
  {
    a[n - 1] = n;
    id[n] = n - 1;
  }

  for (int i = 1; i < n; i++)
    if (id[i] < 0)
    {
      int last, other;
      if (i < a[n - 1])
      {
        last = 1;
        other = a[n - 1] - i + 1;
      }
      else
      {
        last = i - a[n - 1] + 1;
        other = 1;
      }

      cout << '?';
      for (int j = 0; j < n - 1; j++)
        cout << ' ' << other;
      cout << ' ' << last << endl;
      cout.flush();
      int resp;
      cin >> resp;
      assert(resp > 0);
      a[resp - 1] = i;
    }

  cout << '!';
  for (int x : a)
    cout << ' ' << x;
  cout << endl;
  cout.flush();
}