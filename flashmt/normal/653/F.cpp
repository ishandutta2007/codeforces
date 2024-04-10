#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

struct SuffixArray
{
  string s;
  int n;
  vector<int> sa, rank, tempSa, tempRank, c, lcp, prev;

  SuffixArray(string s): s(s)
  {
    n = s.size();
    rank = sa = tempSa = tempRank = lcp = prev = vector<int>(n);
    c = vector<int>(max(266, n));
    construct();
    calcLcp();
  }

  void countingSort(int shift)
  {
    int C = max(266, n);
    c.assign(C, 0);
    for (int x : rank)
      c[x]++;
    for (int i = 0, sum = 0; i < C; i++)
    {
      sum += c[i];
      c[i] = sum - c[i];
    }
    for (int i = 0; i < n; i++)
      if (sa[i] + shift < n) tempSa[c[rank[sa[i] + shift]]++] = sa[i];
      else tempSa[c[rank[sa[i] + shift - n]]++] = sa[i];
    sa = tempSa;
  }

  void construct()
  {
    for (int i = 0; i < n; i++)
    {
      rank[i] = int(s[i]);
      sa[i] = i;
    }
    for (int shift = 1; shift < n; shift <<= 1)
    {
      countingSort(shift);
      countingSort(0);
      int curRank = tempRank[sa[0]] = 0;
      for (int i = 1; i < n; i++)
      {
        if (rank[sa[i]] != rank[sa[i - 1]] || rank[(sa[i] + shift) % n] != rank[(sa[i - 1] + shift) % n])
          curRank++;
        tempRank[sa[i]] = curRank;
      }
      rank = tempRank;
    }
  }

  void calcLcp()
  {
    for (int i = 0; i < n; i++)
      prev[sa[i]] = i ? sa[i - 1] : - 1;
    for (int i = 0, match = 0; i < n; i++)
      if (prev[i] < 0) lcp[i] = 0;
      else
      {
        while (s[(i + match) % n] == s[(prev[i] + match) % n])
          match++;
        lcp[i] = match;
        match = max(0, match - 1);
      }
  }

  void db()
  {
    for (int i : sa)
      if (s[i] >= '(')
        cout << lcp[i] << ' ' << s.substr(i, n - i) << endl;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;

  s += '#';
  SuffixArray sa(s);
  vector<int> r(n); // min j such that s[i..j] is unique
  for (int i : sa.sa)
    if (i < n)
      r[i] = i + sa.lcp[i];

  long long ans = 0;
  vector<vector<int>> id(n * 2 + 1);
  id[n] = {n};
  for (int i = n - 1, x = n; i >= 0; i--)
    if (s[i] == ')') id[++x].push_back(i);
    else
    {
      id[x--].clear();

      // count number of valid ids
      int low = 0, high = size(id[x]) - 1, res = -1;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (id[x][mid] > r[i])
        {
          res = mid;
          low = mid + 1;
        }
        else high = mid - 1;
      }

      ans += res + 1;
      id[x].push_back(i);
    }

  cout << ans << endl;
}