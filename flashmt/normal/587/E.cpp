#include <bits/stdc++.h>
using namespace std;
const int BIT = 30;

struct SegmentTree
{
  int low, mid, high, value;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high) 
  {
    mid = (low + high) / 2;
    value = 0;
    if (low == high) return;
    l = new SegmentTree(low, mid);
    r = new SegmentTree(mid + 1, high);
  }

  void update(int x, int y, int v)
  {
    if (low == x && high == y) value ^= v;
    else
    {
      if (x <= mid) l -> update(x, min(y, mid), v);
      if (mid < y) r -> update(max(x, mid + 1), y, v);
    }
  }

  int get(int x)
  {
    if (low == high)
      return value;
    return (x <= mid ? l -> get(x) : r -> get(x)) ^ value;
  }
};

int n, q, a[200200], b[200200];

void gauss(vector <int> &a)
{
  int pivotCol = 0;
  for (int i = 0; i < BIT; i++)
  {
    int row = -1;
    for (int j = pivotCol; j < a.size(); j++)
      if (a[j] >> i & 1)
      {
        row = j;
        break;
      }

    if (row < 0) continue;

    swap(a[pivotCol], a[row]);
    row = pivotCol++;
    for (int j = row + 1; j < a.size(); j++)
      if (a[j] >> i & 1)
        a[j] ^= a[row];
  }

  a.resize(pivotCol);
}

struct ScoreTree
{
  int low, mid, high;
  vector <int> v;
  ScoreTree *l, *r;

  ScoreTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high) v.push_back(b[low]);
    else
    {
      l = new ScoreTree(low, mid);
      r = new ScoreTree(mid + 1, high);
      v = merge(l -> v, r -> v);
    }
  }

  vector <int> merge(vector <int> a, vector <int> b)
  {
    for (int x : b)
      a.push_back(x);
    gauss(a);
    return a;
  }

  void update(int x)
  {
    if (low == high) v = vector<int>(1, b[low]);
    else
    {
      if (x <= mid) l -> update(x);
      else r -> update(x);
      v = merge(l -> v, r -> v);
    }
  }

  vector <int> get(int x, int y)
  {
    if (low == x && high == y)
      return v;
    vector <int> vLeft, vRight;
    if (x <= mid) vLeft = l -> get(x, min(y, mid));
    if (mid < y) vRight = r -> get(max(x, mid + 1), y);
    if (vLeft.empty()) return vRight;
    if (vRight.empty()) return vLeft;
    return merge(vLeft, vRight);
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int type, l, r, k;

  cin >> n >> q;
  SegmentTree *segmentTree = new SegmentTree(1, n);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    if (i > 1)
      b[i] = a[i] ^ a[i - 1];
    segmentTree -> update(i, i, a[i]);
  }

  ScoreTree *scoreTree;
  if (n > 1) scoreTree = new ScoreTree(2, n);
  while (q--)
  {
    cin >> type >> l >> r;
    if (type == 1)
    {
      cin >> k;
      segmentTree -> update(l, r, k);
      if (l > 1)
      {
        b[l] ^= k;
        scoreTree -> update(l);
      }
      if (r < n)
      {
        b[r + 1] ^= k;
        scoreTree -> update(r + 1);
      }
    }
    else
    {
      vector <int> v;
      if (l < r)
        v = scoreTree -> get(l + 1, r);
      v.push_back(segmentTree -> get(l));
      gauss(v);
      cout << (1 << v.size()) << '\n';
    }
  }
}