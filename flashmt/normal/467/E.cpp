#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, a[500500], prev[500500], next[500500], f[500500], realValues[500500], order[500500];
vector <int> id[500500];
map <int,int> values;

struct SegmentTree
{
  int low, high, mid, value;
  SegmentTree *left, *right;
  
  SegmentTree(int low, int high)
  {
    this -> low = low;
    this -> high = high;
    mid = (low + high) / 2;
    if (low == high) value = prev[low];
    else
    {
      left = new SegmentTree(low, mid);
      right = new SegmentTree(mid + 1, high);
      value = min(left -> value, right -> value);
    }
  }
  
  int get(int x, int y)
  {
    if (x == low && y == high) return value;
    int res = oo;
    if (x <= mid) res = min(res, left -> get(x, min(y, mid)));
    if (mid < y) res = min(res, right -> get(max(x, mid + 1), y));
    return res;
  }
  
  void remove(int x)
  {
    if (low == high) value = oo;
    else
    {
      if (x <= mid) left -> remove(x);
      else right -> remove(x);
      value = min(left -> value, right -> value);
    }
  }
};

int get(int x)
{
  if (!values.count(x)) 
  {
    values[x] = values.size();
    realValues[values[x]] = x;
  }
  return values[x];
}

int main()
{
  ios::sync_with_stdio(0);
  //freopen("e.in", "r", stdin);
  
  cin >> n;
  for (int i = 1; i <= n; i++) 
  {
    cin >> a[i];
    a[i] = get(a[i]);
    if (!id[a[i]].empty()) 
    {
      prev[i] = id[a[i]].back();
      next[id[a[i]].back()] = i;
    }
    else prev[i] = oo;
    
    order[i] = id[a[i]].size();
    id[a[i]].push_back(i);
  }

  SegmentTree tree(1, n);
  vector <int> ans;
  for (int i = 1, j = 1; i <= n; i++)
  {
    f[i] = f[i - 1];
    if (!prev[i]) continue;
    int found = 0;
    
    if (prev[i] + 1 < i)
    {
      int minId = tree.get(prev[i] + 1, i - 1);
      if (minId < prev[i])
      {
        ans.push_back(realValues[a[minId]]);
        ans.push_back(realValues[a[i]]);
        ans.push_back(realValues[a[minId]]);
        ans.push_back(realValues[a[i]]);
        found = 1;
      }
    }
    
    if (!found && order[i] >= 3 && id[a[i]][order[i] - 3] >= j)
    {
      ans.push_back(realValues[a[i]]);
      ans.push_back(realValues[a[i]]);
      ans.push_back(realValues[a[i]]);
      ans.push_back(realValues[a[i]]);
      found = 1;
    }
    
    if (found)
      while (j <= i)
      {
        if (next[j]) tree.remove(next[j]);
        j++;
      }
  }
  
  cout << ans.size() << endl;
  for (int i = 0; i < int(ans.size()); i++) cout << ans[i] << ' ';
}