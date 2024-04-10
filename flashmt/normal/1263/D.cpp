#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> ds(n + 26);
  for (int i = 0; i < n + 26; i++)
    ds[i] =  i;

  function<int(int)> get = [&](int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds[x]);
  };

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (char c : s)
    {
      int di = get(i), dj = get(n + c - 'a');
      if (di != dj)
        ds[di] = dj;
    }
  }

  set<int> s;
  for (int i = 0; i < n; i++)
    s.insert(get(i));
  cout << s.size() << endl;
}