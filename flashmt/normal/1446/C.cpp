#include <bits/stdc++.h>
using namespace std;
const int MAXBIT = 29;

struct Trie
{
  int cnt;
  Trie *child[2];

  Trie()
  {
    cnt = 0;
    child[0] = child[1] = NULL;
  }

  void add(int x, int bit)
  {
    cnt++;
    if (bit < 0)
      return;
    int v = x >> bit & 1;
    for (int i = 0; i < 2; i++)
      if (!child[i])
        child[i] = new Trie();
    child[v]->add(x, bit - 1);
  }

  int solve(int bit)
  {
    if (bit == -1)
      return cnt;
    if (child[0] && child[1])
      return max(child[0]->solve(bit - 1) + min(1, child[1]->cnt), child[1]->solve(bit - 1) + min(1, child[0]->cnt));
    return 0;
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
    trie->add(x, MAXBIT);
  }

  cout << n - trie->solve(MAXBIT) << endl;
}