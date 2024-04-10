#include <bits/stdc++.h>
using namespace std;

int n, c, l[1000100], r[1000100], cur, good = 1, flag[1000100];
int leftChild[1000100], rightChild[1000100];
vector < pair <int,int> > conditions[1000100];
vector <int> ans;

void refine(int x, int low)
{
  if (cur >= low) return;
  if (!rightChild[x]) rightChild[x] = ++cur;
  refine(rightChild[x], low);
}

void visit(int x, int low)
{
  if (l[x])
  {
    leftChild[x] = ++cur;
    visit(cur, l[x]);
    l[x] = 0;
  }
  
  if (r[x])
  {
    rightChild[x] = ++cur;
    visit(cur, r[x]);
    r[x] = 0;
  }
  
  if (cur >= low) return;
  if (!rightChild[x]) rightChild[x] = ++cur;
  visit(rightChild[x], low);
}

void check(int x)
{
  flag[x] = 1;
  for (auto c : conditions[x])
    if (c.second)
    {
      if (!rightChild[c.first] || !flag[rightChild[c.first]]) good = 0;
    }
    else
    {
      if (!leftChild[c.first] || !flag[leftChild[c.first]]) good = 0;
    }
    
  if (leftChild[x]) check(leftChild[x]);
  ans.push_back(x);
  if (rightChild[x]) check(rightChild[x]);
  flag[x] = 0;
}

int main()
{
  ios::sync_with_stdio(0);
  int x[100100], y[100100];
  string side[100100];
  cin >> n >> c;
  for (int i = 0; i < c; i++)
  {
    cin >> x[i] >> y[i] >> side[i];
    if (x[i] >= y[i])
    {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    if (side[i] == "LEFT") l[x[i]] = max(l[x[i]], y[i]);
    else r[x[i]] = max(r[x[i]], y[i]);
    conditions[y[i]].push_back(make_pair(x[i], side[i] == "RIGHT"));
  }
  
  for (int i = 1; i <= n; i++)
    if (l[i] && r[i] && l[i] >= r[i])
    {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  
  cur = 1;
  visit(1, n);
  check(1);
  
  if (!good) 
  {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  
  for (auto x : ans) cout << x << ' ';
}