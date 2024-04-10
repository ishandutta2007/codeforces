#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l, k, cnt[128] = {0};
  string s;
  cin >> n >> l >> k >> s;
  for (char c : s)
    cnt[c]++;

  vector<string> a(n);
  int equal = 0;
  char c = 'a';
  for (int i = 0; i < l; i++)
  {
    for (int j = equal; j < k; j++)
    {
      while (!cnt[c])
        c++;
      a[j] += c;
      cnt[c]--;
    }
    while (a[equal][i] < a[k - 1][i])
      equal++;
  }

  for (int i = 0; i < n; i++)
  {
    cout << a[i];
    for (int j = a[i].size(); j < l; j++)
    {
      while (!cnt[c])
        c++;
      cout << c;
      cnt[c]--;
    }
    cout << endl;
  }
}