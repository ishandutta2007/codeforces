#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

template<typename T>
struct FenwickTree
{
  int n, indexBase;
  vector<T> a;

  FenwickTree(int n, int indexBase = 1): n(n), indexBase(indexBase)
  {
    a = vector<T>(n + 1, 0);
  }

  void add(int x, T v)
  {
    for (int i = x + 1 - indexBase; i <= n; i += i & -i)
      a[i] += v;
  }

  T get(int x)
  {
    T res = 0;
    for (int i = x + 1 - indexBase; i; i -= i & -i)
      res += a[i];
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string s, t;
    cin >> n >> s >> t;

    string ss = s;
    sort(begin(ss), end(ss));
    if (ss >= t)
    {
      cout << "-1\n";
      continue;
    }

    FenwickTree<int> tree(n, 0);
    queue<int> id[26];
    set<int> alive;
    for (int i = 0; i < n; i++)
    {
      id[s[i] - 'a'].push(i);
      alive.insert(i);
    }

    long long ans = 1LL * n * n, cnt = 0;
    for (int i = 0; i < n; i++)
    {
      int x = *begin(alive);
      if (s[x] < t[i])
      {
        ans = min(ans, cnt);
        break;
      }

      int curC = t[i] - 'a';
      for (int c = 0; c < curC; c++)
        if (!empty(id[c]))
        {
          int curId = id[c].front();
          int add = tree.get(curId);
          ans = min(ans, cnt + curId + add - i);
        }

      if (empty(id[curC]))
        break;

      int curId = id[curC].front();
      id[curC].pop();
      alive.erase(curId);
      int add = tree.get(curId);
      cnt += curId + add - i;
      tree.add(0, 1);
      tree.add(curId, -1);
    }

    cout << ans << '\n';
  }
}