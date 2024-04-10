#include <bits/stdc++.h>
using namespace std;

long long cnt[30][2];

struct Trie
{
  int v;
  Trie *child[2];

  Trie()
  {
    v = 0;
    child[0] = child[1] = NULL;
  }

  void add(int i, int x)
  {
    v++;
    if (i < 0)
      return;

    int bit = x >> i & 1;
    if (child[bit ^ 1])
      cnt[i][bit] += child[bit ^ 1]->v;

    if (!child[bit])
      child[bit] = new Trie();
    child[bit]->add(i - 1, x);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  Trie *trie = new Trie();
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    trie->add(29, x);
  }

  int ans = 0;
  long long inv = 0;
  for (int bit = 29; bit >= 0; bit--)
    if (cnt[bit][0] <= cnt[bit][1]) inv += cnt[bit][0];
    else
    {
      inv += cnt[bit][1];
      ans |= 1 << bit;
    }

  cout << inv << ' ' << ans << endl;
}