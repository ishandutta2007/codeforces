#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const string ALPHABET = "ACGT";

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

int getChar(char c)
{
  for (int i = 0; i < size(ALPHABET); i++)
    if (ALPHABET[i] == c)
      return i;
  return -1;
}

FenwickTree<int> *tree[4][11][11];

void update(int x, int c, int v)
{
  for (int i = 1; i <= 10; i++)
    tree[c][i][x % i]->add(x / i, v);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int q;
  cin >> s >> q;
  int n = size(s);
  for (int i = 0; i < 4; i++)
    for (int j = 1; j <= 10; j++)
      for (int k = 0; k < j; k++)
        tree[i][j][k] = new FenwickTree<int>(n / j + 1, 0);

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    a[i] = getChar(s[i]);
    update(i, a[i], 1);
  }

  while (q--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int i;
      char c;
      cin >> i >> c;
      i--;
      update(i, a[i], -1);
      a[i] = getChar(c);
      update(i, a[i], 1);
    }
    else
    {
      int l, r;
      string e;
      cin >> l >> r >> e;
      l--; r--;
      if (size(e) > r - l + 1)
        e = e.substr(0, r - l + 1);

      int len = size(e), ans = 0;
      for (int i = 0; i < len; i++)
      {
        int c = getChar(e[i]);
        int mod = (l + i) % len, last = r / len * len + mod;
        if (last > r)
          last -= len;
        ans += tree[c][len][mod]->get(last / len);
        if ((l + i) / len)
          ans -= tree[c][len][mod]->get((l + i) / len - 1);
      }

      cout << ans << '\n';
    }
  }
}