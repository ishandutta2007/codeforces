#include <bits/stdc++.h>
using namespace std;
const int BOUND = 14;

int n, suffix[20], suffixLen;
long long fact[20];

void fromIndex(long long index, int p[])
{
  vector<int> seen(suffixLen, 0);
  for (int i = 0; i < suffixLen; i++)
  {
    int cnt = index / fact[suffixLen - 1 - i];
    index %= fact[suffixLen - 1 - i];
    for (int j = 0; j < suffixLen; j++)
      if (!seen[j])
      {
        cnt--;
        if (cnt < 0)
        {
          p[i] = j;
          seen[j] = 1;
          break;
        }
      }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> n >> q;
  fact[0] = 1;
  for (int i = 1; i <= BOUND; i++)
    fact[i] = fact[i - 1] * i;

  suffixLen = min(n, BOUND);
  int fixPart = n - suffixLen;
  for (int i = 0; i < suffixLen; i++)
    suffix[i] = i;

  long long index = 0;
  while (q--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int l, r;
      cin >> l >> r;
      l--;
      r--;

      fromIndex(index, suffix);
      long long ans = r - l + 1;

      if (l < fixPart)
      {
        int rr = min(fixPart - 1, r);
        ans += (rr + l) * (rr - l + 1LL) / 2;
      }

      if (r >= fixPart)
      {
        l = max(0, l - fixPart);
        r -= fixPart;
        for (int i = l; i <= r; i++)
          ans += fixPart + suffix[i];
      }

      cout << ans << '\n';
    }
    else
    {
      int x;
      cin >> x;
      index += x;
    }
  }
}