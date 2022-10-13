#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, a[100100];
  string s;
  vector <int> id[2];
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++)
  {
    a[i + 1] = a[i] + s[i] - '0';
    id[s[i] - '0'].push_back(i + 1);
  }

  for (int i = 0; i + k <= n; i++)
  {
    if (a[i] == i && a[n] - a[i + k] == n - (i + k))
    {
      cout << "tokitsukaze" << endl;
      return 0;
    }
    if (!a[i] && !(a[n] - a[i + k]))
    {
      cout << "tokitsukaze" << endl;
      return 0;
    }
  }

  int found = 0;
  for (int i = 0; i + k <= n; i++)
    for (int z = 0; z < 2; z++)
    {
      int first1 = id[z][0];
      if (i + 1 <= first1 && first1 <= i + k)
      {
        int first1Id = upper_bound(id[z].begin(), id[z].end(), i + k) - id[z].begin();
        if (first1Id == id[z].size()) first1 = n + 1;
        else first1 = id[z][first1Id];
      }
      int last1 = id[z].back();
      if (i + 1 <= last1 && last1 <= i + k)
      {
        int last1Id = lower_bound(id[z].begin(), id[z].end(), i + 1) - id[z].begin();
        if (last1Id == 0) last1 = 0;
        else last1 = id[z][last1Id - 1];
      }
      if (last1 - first1 >= k)
        found = 1;
    }

  cout << (found ? "once again" : "quailty") << endl;
}