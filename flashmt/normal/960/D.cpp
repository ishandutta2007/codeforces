#include <bits/stdc++.h>
using namespace std;
const int LEVEL = 59;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  long long shift[60] = {0};
  cin >> q;
  while (q--)
  {
    int op;
    long long x, k;
    cin >> op >> x;
    int level = 63 - __builtin_clzll(x);
    if (op <= 2)
    {
      cin >> k;
      if (k < 0)
        k = (1LL << level) - (-k) % (1LL << level);
      for (int i = level; i <= (op == 1 ? level : LEVEL); i++)
      {
        shift[i] = (shift[i] + k) & ((1LL << i) - 1);
        k <<= 1;
      }
    }
    else
    {
      cout << x;
      for (int i = level; i; i--)
      {
        long long numNode = 1LL << i;
        x = (x - numNode + shift[i]) & (numNode - 1) | numNode;
        x >>= 1;
        numNode >>= 1;
        x = (x - shift[i - 1]) & (numNode - 1) | numNode;
        cout << ' ' << x;
      }
      cout << '\n';
    }
  }
}