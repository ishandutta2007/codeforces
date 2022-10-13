#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, q;
    string a;
    cin >> n >> q >> a;
    vector<int> s(n + 1);
    for (int i = 0, sign = 1; i < n; i++)
    {
      s[i + 1] = s[i] + (a[i] == '+' ? 1 : -1) * sign;
      sign *= -1;
    }

    auto get = [&](int l, int r, int i)
    {
      int prefix = l % 2 ? s[l] - s[i - 1] : s[i - 1] - s[l];
      int suffix = i % 2 ? s[i] - s[r] : s[r] - s[i];
      return (i - l - 1) % 2 ? prefix - suffix : prefix + suffix;
    };

    while (q--)
    {
      int l, r;
      cin >> l >> r;
      l--;
      if (s[r] == s[l]) cout << "0\n";
      else
      {
        vector<int> ans;
        if (l % 2 == r % 2)
          ans.push_back(++l);

        if (l < r)
        {
          int vl = get(l, r, l + 1), vr = get(l, r, r);
          if (!vl) ans.push_back(l + 1);
          else if (!vr) ans.push_back(r);
          else
          {
            int low = l + 1, high = r;
            while (low <= high)
            {
              int mid = (low + high) / 2;
              int vm = get(l, r, mid);
              if (!vm)
              {
                ans.push_back(mid);
                break;
              }
              if ((vm > 0) ^ (vl > 0)) high = mid - 1;
              else low = mid + 1;
            }
          }
        }

        cout << size(ans) << '\n';
        for (int x : ans)
          cout << x << ' ';
        cout << '\n';
      }
    }
  }
}