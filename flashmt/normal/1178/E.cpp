#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  int i = 0, j = s.size() - 1;
  vector<int> id;
  while (j - i >= 3)
  {
    int found = -1;
    for (int u = i; u < i + 2; u++)
      for (int v = j - 1; v <= j; v++)
        if (s[u] == s[v])
          found = u;

    assert(found >= 0);
    id.push_back(found);

    i += 2;
    j -= 2;
  }

  for (int u : id)
    cout << s[u];

  if (i <= j)
    cout << s[i];

  reverse(id.begin(), id.end());
  for (int u : id)
    cout << s[u];
}