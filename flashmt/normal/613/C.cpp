#include <bits/stdc++.h>
using namespace std;

string rev(string s)
{
  reverse(begin(s), end(s));
  return s;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  string ans;
  int num = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    ans += string(a[i], i + 'a');
  }

  for (int repeat = 1; repeat <= 100000; repeat++)
  {
    int isGood = 1;
    vector<int> odd;
    for (int i = 0; i < n; i++)
      if (a[i] % repeat) isGood = 0;
      else if (a[i] / repeat % 2) odd.push_back(i);

    if (!isGood || size(odd) >= 2)
      continue;

    int cut = repeat * (empty(odd) ? 2 : 1);
    if (cut > num)
    {
      num = cut;
      string half;
      for (int i = 0; i < n; i++)
        half += string(a[i] / repeat / 2, i + 'a');
      string period = half;
      if (!empty(odd))
        period += char(odd[0] + 'a');
      period += rev(half);

      ans = "";
      for (int i = 0; i < repeat; i++)
        ans += period;
    }
  }

  cout << num << endl;
  cout << ans << endl;
}