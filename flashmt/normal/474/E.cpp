#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
  int low, mid, high, value, idMax;
  SegmentTree *left, *right;
  
  SegmentTree(int low, int high)
  {
    this -> low = low;
    this -> high = high;
    mid = (low + high) / 2;
    value = idMax = 0;
    if (low == high) return;
    left = new SegmentTree(low, mid);
    right = new SegmentTree(mid + 1, high);
  }
  
  void update(int x, int v, int id)
  {
    if (value < v)
    {
      value = v;
      idMax = id;
    }
    if (low == high) return;
    if (x <= mid) left -> update(x, v, id);
    else right -> update(x, v, id);
  }
  
  pair <int,int> get(int x, int y)
  {
    if (low == x && high == y) return make_pair(value, idMax);
    pair <int,int> u(0, 0), v(0, 0);
    if (x <= mid) u = left -> get(x, min(y, mid));
    if (mid < y) v = right -> get(max(x, mid + 1), y);
    return max(u, v);
  }
};

int n, d, f[100100], trace[100100];
long long h[100100];
map <long long,int> m;
SegmentTree *tree;

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) 
  {
    cin >> h[i];
    m[h[i]] = 0;
  }
  m[1LL << 60] = 0;
  
  int id = 0;
  for (map <long long,int>::iterator it = m.begin(); it != m.end(); it++)
    it -> second = ++id;
    
  tree = new SegmentTree(1, id);
  int idAns = 1;
  for (int i = 1; i <= n; i++)
  {
    f[i] = 1;
    
    int x = m.upper_bound(h[i] - d) -> second;
    if (x > 1)
    {
      pair <int,int> u = tree -> get(1, x - 1);
      if (f[i] < u.first + 1)
      {
        f[i] = u.first + 1;
        trace[i] = u.second;
      }
    }
    
    x = m.lower_bound(h[i] + d) -> second;
    if (x <= id)
    {
      pair <int,int> u = tree -> get(x, id);
      if (f[i] < u.first + 1)
      {
        f[i] = u.first + 1;
        trace[i] = u.second;
      }
    }
    
    tree -> update(m[h[i]], f[i], i);
    if (f[i] > f[idAns]) idAns = i;
  }
  
  cout << f[idAns] << endl;
  vector <int> jumps;
  for (int i = idAns; i; i = trace[i]) jumps.push_back(i);
  for (int i = int(jumps.size()) - 1; i >= 0; i--) cout << jumps[i] << ' ';
}