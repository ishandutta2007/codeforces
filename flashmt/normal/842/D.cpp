#include <bits/stdc++.h>
using namespace std;
const int MAX_BIT = 18;

struct Trie 
{
  int bit, from, to, cnt;
  Trie *child[2];

  Trie(int bit, int from, int to): bit(bit), from(from), to(to) {
    child[0] = child[1] = NULL;
    cnt = 0;
  }

  void add(int x)
  {
    cnt++;
    if (bit < 0)
      return;
    if (!child[0])
      child[0] = new Trie(bit - 1, from, to - (1 << bit));
    if (!child[1])
      child[1] = new Trie(bit - 1, from + (1 << bit), to);
    child[x >> bit & 1] -> add(x);
  }

  int query(int x)
  {
    int l = 0, r = 1, res;
    if (x >> bit & 1)
    {
      l = 1;
      r = 0;
    }
    
    if (child[l] -> cnt == 0) res = child[l] -> from;
    else if (child[l] -> cnt < (to - from + 1) / 2) res = child[l] -> query(x);
    else if (child[r] -> cnt == 0) res = child[r] -> from;
    else res = child[r] -> query(x);

    if (x >> bit & 1)
      res ^= 1 << bit;
    return res;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m, x, y = 0;
  set <int> s;
  Trie *trie = new Trie(MAX_BIT, 0, (1 << MAX_BIT + 1) - 1);
  cin >> n >> m;
  while (n--)
  {
    cin >> x;
    if (!s.count(x))
    {
      trie -> add(x);
      s.insert(x);
    }
  }
  while (m--)
  {
    cin >> x;
    y ^= x;
    cout << trie -> query(y) << '\n';
  }
}