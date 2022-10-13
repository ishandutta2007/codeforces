#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p;
  vector<long long> a;
  cin >> n >> m >> p;
  for (int i = 0; i < n; i++)
  {
    string s;
    long long x = 0;
    cin >> s;
    for (int j = 0; j < m; j++)
      if (s[j] == '1')
        x |= 1LL << j;
    a.push_back(x);
  }

  int ans = 0;
  vector<int> maskAns;
  for (int turn = 0; turn < 50; turn++)
  {
    int id = rng() % n;
    vector<int> bits;
    for (int i = 0; i < m; i++)
      if (a[id] >> i & 1)
        bits.push_back(i);

    int sz = bits.size();
    if (!sz)
      continue;

    vector<int> cnt(1 << sz);
    for (int i = 0; i < n; i++)
    {
      int mask = 0;
      for (int j = 0; j < sz; j++)
        if (a[i] >> bits[j] & 1)
          mask |= 1 << j;
      cnt[mask]++;
    }

    for (int i = 0; i < sz; i++)
      for (int mask = (1 << sz) - 1; mask; mask--)
        if (mask >> i & 1)
          cnt[mask ^ 1 << i] += cnt[mask];

    for (int mask = 1; mask < 1 << sz; mask++)
      if (cnt[mask] * 2 >= n)
      {
        int numBit = __builtin_popcount(mask);
        if (numBit > ans)
        {
          ans = numBit;
          maskAns.clear();
          for (int i = 0; i < sz; i++)
            if (mask >> i & 1)
              maskAns.push_back(bits[i]);
        }
      }
  }

  vector<int> ansBits(m);
  for (int i : maskAns)
    ansBits[i] = 1;
  for (int i : ansBits)
    cout << i;
  cout << endl;
}