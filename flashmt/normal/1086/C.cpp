#include <bits/stdc++.h>
using namespace std;

string s, a, b;
int k, match[26], used[26];
vector<int> charIds;

int go(int i, int isEqual)
{
  if (i == charIds.size())
    return 1;

  int id = charIds[i], x = s[id] - 'a', y = a[id] - 'a';
  if (match[x] >= 0)
  {
    if (isEqual && match[x] < y)
      return 0;
    return go(i + 1, isEqual && match[x] == y);
  }

  if (isEqual && used[y] < 0)
  {
    match[x] = y;
    used[y] = x;
    if (go(i + 1, 1))
      return 1;
    match[x] = used[y] = -1;
  }

  for (int c = (isEqual ? y + 1 : 0); c < k; c++)
    if (used[c] < 0)
    {
      match[x] = c;
      used[c] = x;
      if (go(i + 1, 0))
        return 1;
      match[x] = used[c] = -1;
      break;
    }

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, flagChar[26] = {0}, flagPair[26][26] = {0};
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cin >> k >> s >> a >> b;
    int n = s.size();

    charIds.clear();
    for (int i = 0; i < n; i++)
    {
      int x = s[i] - 'a', y = a[i] - 'a';
      if (flagChar[x] != iTest || flagPair[x][y] != iTest)
        charIds.push_back(i);
      flagChar[x] = flagPair[x][y] = iTest;
    }

    memset(match, -1, sizeof match);
    memset(used, -1, sizeof used);
    if (!go(0, 1)) cout << "NO\n";
    else
    {
      int isGood = 1;
      for (int i = 0; i < n; i++)
      {
        int x = s[i] - 'a', y = b[i] - 'a';
        if (match[x] != y)
        {
          isGood &= match[x] < y;
          break;
        }
      }

      if (!isGood) cout << "NO\n";
      else
      {
        cout << "YES\n";
        for (int i = 0; i < k; i++)
        {
          if (match[i] < 0)
            for (int j = 0; j < k; j++)
              if (used[j] < 0)
              {
                match[i] = j;
                used[j] = i;
                break;
              }

          cout << char(match[i] + 'a');
        }
        cout << '\n';
      }
    }
  }
}