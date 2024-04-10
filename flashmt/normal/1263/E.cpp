#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct SegmentTree
{
  int low, mid, high;
  int minValue, maxValue, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    minValue = maxValue = save = 0;
    if (low != high)
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void update(int x, int y, int value)
  {
    if (low == x && high == y)
    {
      minValue += value;
      maxValue += value;
      save += value;
    }
    else
    {
      if (x <= mid)
        l->update(x, min(y, mid), value);
      if (mid < y)
        r->update(max(x, mid + 1), y, value);
      minValue = min(l->minValue, r->minValue) + save;
      maxValue = max(l->maxValue, r->maxValue) + save;
    }
  }
};


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, cursor = 0, maxCursor = 0;
  string s;
  cin >> n >> s;
  for (char c : s)
    if (c == 'L') cursor = max(0, cursor - 1);
    else if (c == 'R') cursor++;
    else maxCursor = max(maxCursor, cursor);

  SegmentTree tree(0, maxCursor);
  cursor = 0;
  vector<int> text(n, 0);
  int ans = 0, value = 0;
  for (char c : s)
  {
    if (c == 'L') cursor = max(0, cursor - 1);
    else if (c == 'R') cursor++;
    else
    {
      if (text[cursor])
      {
        tree.update(cursor, maxCursor, -text[cursor]);
        value -= text[cursor];
      }

      if (c == '(' || c == ')')
      {
        text[cursor] = c == '(' ? 1 : -1;
        value += text[cursor];
        tree.update(cursor, maxCursor, text[cursor]);
      }
      else text[cursor] = 0;

      if (value || tree.minValue < 0) ans = -1;
      else ans = tree.maxValue;
    }
    cout << ans << ' ';
  }
}