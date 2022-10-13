#include <bits/stdc++.h>
using namespace std;
const int C = 52;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<vector<int>> a;
    vector<vector<vector<int>>> id(n, vector<vector<int>>(C));
    for (int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      vector<int> cur;
      for (char c : s)
        if (c <= 'Z') cur.push_back(c - 'A');
        else cur.push_back(c - 'a' + 26);
      a.push_back(cur);
      for (int j = 0; j < size(cur); j++)
        id[i][cur[j]].push_back(j);
    }

    vector<pair<int, int>> order;
    for (int c = 0; c < C; c++)
      for (int mask = 0; mask < 1 << n; mask++)
        order.push_back({c, mask});

    auto cmp = [&](pair<int, int> u, pair<int, int> v)
    {
      int c = u.first, i = u.second & 1;
      int cc = v.first, ii = v.second & 1;
      if (c == cc) return i < ii;
      else if (i >= size(id[0][c]) && ii >= size(id[0][cc])) return c < cc;
      else if (i >= size(id[0][c])) return false;
      else if (ii >= size(id[0][cc])) return true;
      else return id[0][c][i] < id[0][cc][ii];
    };

    sort(begin(order), end(order), cmp);

    vector<vector<int>> f(C, vector<int>(1 << n));
    vector<vector<pair<int, int>>> tr(C, vector<pair<int, int>>(1 << n, pair<int, int>(-1, -1)));
    int ans = 0, ansC = -1, ansMask;
    for (auto [c, mask] : order)
    {
      int isValid = 1;
      vector<int> curId(n);
      for (int i = 0; i < n; i++)
      {
        int bit = mask >> i & 1;
        if (bit >= size(id[i][c])) isValid = 0;
        else curId[i] = id[i][c][bit];
      }

      if (!isValid)
        continue;

      f[c][mask] = 1;
      for (int cc = 0; cc < C; cc++)
      {
        int isGood = 1, prevMask = 0;
        for (int i = 0; i < n; i++)
          if (size(id[i][cc]) == 2 && id[i][cc][1] < curId[i]) prevMask |= 1 << i;
          else if (!empty(id[i][cc]) && id[i][cc][0] < curId[i]);
          else
          {
            isGood = 0;
            break;
          }

        if (isGood && f[cc][prevMask] + 1 > f[c][mask])
        {
          f[c][mask] = f[cc][prevMask] + 1;
          tr[c][mask] = {cc, prevMask};
        }
      }

      if (f[c][mask] > ans)
      {
        ans = f[c][mask];
        ansC = c;
        ansMask = mask;
      }
    }

    string lcs;
    for (int c = ansC, mask = ansMask; c >= 0;)
    {
      if (c < 26) lcs += char('A' + c);
      else lcs += char('a' + c - 26);
      auto [cc, prevMask] = tr[c][mask];
      c = cc;
      mask = prevMask;
    }
    reverse(begin(lcs), end(lcs));
    cout << ans << endl;
    cout << lcs << endl;
  }
}