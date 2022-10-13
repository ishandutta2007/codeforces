#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s, t;
  cin >> n >> s >> t;

  vector<int> ans;

  auto shift = [&](int x)
  {
    ans.push_back(x);
    if (x != n)
      reverse(begin(s), begin(s) + n - x);
    reverse(begin(s), end(s));
  };

  // maintain s[0..i] is reverse of t[0..i]
  for (int i = 0; i < n; i++)
  {
    int j = i;
    while (j < n && s[j] != t[i])
      j++;
    if (j == n)
    {
      cout << -1 << endl;
      return 0;
    }

    if (j != n - 1)
    {
      shift(n);
      shift(j);
    }
    assert(s[n - 1] == t[i]);
    shift(1);
  }

  shift(n);
  assert(s == t);

  cout << size(ans) << endl;
  for (int x : ans)
    cout << x << ' ';
}