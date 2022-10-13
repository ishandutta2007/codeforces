#include <bits/stdc++.h>
using namespace std;

struct Trie
{
  Trie *next[2];
  int id;

  Trie()
  {
    id = -1;
    next[0] = next[1] = NULL;
  }

  void add(int i, int x, int id)
  {
    if (i < 0)
    {
      this->id = id;
      return;
    }

    int bit = x >> i & 1;
    if (!next[bit])
      next[bit] = new Trie();
    next[bit]->add(i - 1, x, id);
  }

  int get(int i, int x, int k, int isGreater)
  {
    if (i < 0)
      return id;

    if (isGreater)
    {
      for (int j = 0; j < 2; j++)
        if (next[j])
          return next[j]->get(i - 1, x, k, 1);
    }

    int bit = x >> i & 1;
    if (k >> i & 1)
      return next[bit ^ 1] ? next[bit ^ 1]->get(i - 1, x, k, 0) : -1;
    if (next[bit ^ 1])
      return next[bit ^ 1]->get(i - 1, x, k, 1);
    return next[bit] ? next[bit]->get(i - 1, x, k, 0) : -1;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (!k)
  {
    cout << n << endl;
    for (int i = 1; i <= n; i++)
      cout << i << ' ';
    return 0;
  }

  int numBit = 32 - __builtin_clz(k);
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back({x, i});
  }
  sort(begin(a), end(a));

  vector<int> ans;
  for (int i = 0; i < n;)
  {
    int j = i;
    Trie *trie = new Trie();
    while (j < n && a[j].first >> numBit == a[i].first >> numBit)
    {
      trie->add(numBit - 1, a[j].first, a[j].second);
      j++;
    }

    int found = 0;
    while (i < j)
    {
      auto [x, id] = a[i++];
      int res = trie->get(numBit - 1, x, k, 0);
      if (res >= 0 && !found)
      {
        found = 1;
        ans.push_back(id);
        ans.push_back(res);
      }
    }
    if (!found)
      ans.push_back(a[j - 1].second);
  }

  if (size(ans) < 2) cout << -1 << endl;
  else
  {
    cout << size(ans) << endl;
    for (int x : ans)
      cout << x + 1 << ' ';
  }
}