#include <bits/stdc++.h>
using namespace std;

int n, l[3030], r[3030], pre[3030];
string w[3030], target[3030], from, to;

void extend(vector<int> bad)
{
  // extend r
  int id = bad[0];
  while (1)
  {
    int stop = 0;
    for (int i : bad)
      if (++r[i] == w[i].size())
        stop = 1;
    if (stop)
      break;

    char c = w[id][r[id]];
    for (int i : bad)
      if (w[i][r[i]] != c)
        stop = 1;
    if (stop)
      break;
  }
  for (int i : bad)
    r[i]--;

  // extend l
  while (1)
  {
    int stop = 0;
    for (int i : bad)
      if (!l[i]--)
        stop = 1;
    if (stop)
      break;

    char c = w[id][l[id]];
    for (int i : bad)
      if (w[i][l[i]] != c)
        stop = 1;
    if (stop)
      break;
  }
  for (int i : bad)
    l[i]++;
}

void buildPre(string &p)
{
  pre[0] = -1;
  int i = 0, j = -1;
  while (i < p.size())
  {
    while (j >= 0 && p[i] != p[j])
      j = pre[j];
    i++;
    j++;
    pre[i] = j >= p.size() || p[i] != p[j] ? j : pre[j];
  }
}

int match(string &s, string &p)
{
  int i = 0, j = 0;
  while (i < s.size())
  {
    while (j >= 0 && s[i] != p[j])
      j = pre[j];
    i++;
    j++;
    if (j >= p.size())
      return i - p.size();
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> w[i];

  vector<int> good, bad;
  for (int i = 0; i < n; i++)
  {
    cin >> target[i];
    l[i] = r[i] = -1;
    for (int j = 0; j < w[i].size(); j++)
      if (w[i][j] != target[i][j])
      {
        if (l[i] < 0)
          l[i] = j;
        r[i] = j;
      }

    if (l[i] < 0) good.push_back(i);
    else
    {
      bad.push_back(i);
      string curFrom = w[i].substr(l[i], r[i] - l[i] + 1);
      string curTo = target[i].substr(l[i], r[i] - l[i] + 1);
      if (from.empty())
      {
        from = curFrom;
        to = curTo;
      }
      else if (from != curFrom || to != curTo)
      {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  extend(bad);
  int id = bad[0];
  from = w[id].substr(l[id], r[id] - l[id] + 1);
  to = target[id].substr(l[id], r[id] - l[id] + 1);
  buildPre(from);

  for (int i = 0; i < n; i++)
    if (match(w[i], from) != l[i])
    {
      cout << "NO" << endl;
      return 0;
    }

  cout << "YES" << endl << from << endl << to << endl;
}