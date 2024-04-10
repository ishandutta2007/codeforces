#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long a[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long maxA = *max_element(a, a + n);
  for (int i = 0; i < n; i++)
    a[i] = maxA - a[i];

  vector<int> f(n + 1, oo);
  f[0] = 0;

  for (int bit = 0; bit < 60; bit++)
  {
    vector<long long> b;
    vector<int> cnt(3, 0);
    for (int i = 0; i < n; i++)
    {
      b.push_back(a[i] % (1LL << bit + 1));
      cnt[a[i] >> bit & 1]++;
    }
    sort(b.begin(), b.end());

    auto compare = [&](long long x, long long y)
    {
      return x % (1LL << bit) < y % (1LL << bit);
    };

    vector<int> oldF(f);
    f.assign(n + 1, oo);
    // Assume that there are i numbers with carry value
    int oldCnt0 = cnt[0];
    for (int i = 0; i <= n; i++)
    {
      if (i && bit)
      {
        if (!cnt[0] || (cnt[1] && compare(b[cnt[0] - 1], b[oldCnt0 + cnt[1] - 1])))
        {
          cnt[1]--;
          cnt[2]++;
        }
        else cnt[0]--;
      }

      f[cnt[2]] = min(f[cnt[2]], oldF[i] + n - cnt[0] - cnt[2]);
      f[n - cnt[0]] = min(f[n - cnt[0]], oldF[i] + cnt[0] + cnt[2]);
    }
  }

  cout << f[0] << endl;
}