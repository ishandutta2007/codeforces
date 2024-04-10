#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

struct Trie
{
  Trie *child[2];
  int value[2];

  Trie()
  {
    value[0] = value[1] = 0;
    child[0] = child[1] = NULL;
  }

  void add(int bit, int a, int id, int curValue)
  {
    if (bit < 0)
      return;

    int curBitA = a >> bit & 1;
    int curBit = (a ^ id) >> bit & 1;
    if (!child[curBit])
      child[curBit] = new Trie();
    child[curBit]->add(bit - 1, a, id, curValue);
    child[curBit]->value[curBitA] = max(child[curBit]->value[curBitA], curValue);
  }

  int get(int bit, int a, int id)
  {
    if (bit < 0)
      return 0;

    int res = 0;
    int curBitId = id >> bit & 1;
    int curBit = (a ^ id) >> bit & 1;
    if (child[curBit])
      res = child[curBit]->get(bit - 1, a, id);

    // let B[i] = (A[i], i)
    // B[i] = 00 -> 01 good, 10 bad
    //        01 -> 11 good, 00 bad
    //        10 -> 00 good, 11 bad
    //        11 -> 10 good, 01 bad
    if (child[curBit ^ 1])
      res = max(res, child[curBit ^ 1]->value[curBitId]);
    return res;
  }
};

const int BIT = 29;

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
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    Trie *trie = new Trie();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int f = trie->get(BIT, a[i], i) + 1;
      ans = max(ans, f);
      trie->add(BIT, a[i], i, f);
    }

    cout << ans << '\n';
  }
}