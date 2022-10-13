#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long t;
  string s;
  cin >> n >> t >> s;
  t -= 1 << (s[n - 1] - 'a');
  t += 1 << (s[n - 2] - 'a');

  int cnt[26] = {0};
  for (int i = 0; i < n - 2; i++)
  {
    cnt[s[i] - 'a']++;
    t += 1 << (s[i] - 'a');
  }

  if (t < 0)
  {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 25; i >= 0; i--)
    while (cnt[i]--)
      if (t >= 2 << i)
        t -= 2 << i;

  cout << (t ? "No" : "Yes") << endl;
}