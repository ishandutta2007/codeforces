#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;

struct SegmentTree
{
  int low, mid, high;
  int coef, saveCoef, flip;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = low + (high - low) / 2;
    flip = saveCoef = 0;
    if (low == high) coef = (low >= 0 ? 1 : -1);
    else
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void pushDown()
  {
    if (saveCoef)
    {
      l->coef = l->saveCoef = saveCoef;
      r->coef = r->saveCoef = saveCoef;
      l->flip = r->flip = 0;
      saveCoef = 0;
    }
    if (flip)
    {
      l->flip ^= 1;
      r->flip ^= 1;
      flip = 0;
    }
  }

  void assign(int x, int y, int c)
  {
    if (x > y)
      return;
    if (low == x && high == y)
    {
      coef = c;
      saveCoef = c;
      flip = 0;
      return;
    }
    pushDown();
    if (x <= mid)
      l->assign(x, min(y, mid), c);
    if (mid < y)
      r->assign(max(x, mid + 1), y, c);
  }

  void doFlip(int x, int y)
  {
    if (x > y)
      return;
    if (low == x && high == y)
    {
      flip ^= 1;
      return;
    }
    pushDown();
    if (x <= mid)
      l->doFlip(x, min(y, mid));
    if (mid < y)
      r->doFlip(max(x, mid + 1), y);
  }

  int get(int x)
  {
    if (low == high)
      return flip ? -coef : coef;
    pushDown();
    int res = x <= mid ? l->get(x) : r->get(x);
    return flip ? -res : res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q, a[100000];
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  SegmentTree *tree = new SegmentTree(-MAX, MAX);
  while (q--)
  {
    char op;
    int x;
    cin >> op >> x;
    if (op == '<')
    {
      if (x <= 0)
      {
        tree->assign(-MAX, x - 1, 1);
        tree->assign(1 - x, MAX, 1);
      }
      else
      {
        tree->assign(-MAX, -x, 1);
        tree->doFlip(1 - x, x - 1);
        tree->assign(x, MAX, 1);
      }
    }
    else
    {
      if (x >= 0)
      {
        tree->assign(x + 1, MAX, -1);
        tree->assign(-MAX, -x - 1, -1);
      }
      else
      {
        tree->assign(-x, MAX, -1);
        tree->doFlip(x + 1, -x - 1);
        tree->assign(-MAX, x, -1);
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << tree->get(a[i]) * abs(a[i]) << " \n"[i == n - 1];
}