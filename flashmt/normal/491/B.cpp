#include <bits/stdc++.h>
using namespace std;
const int oo = 2000111000;

struct Point
{
  int x, y, id, isRestaurant;
  
  Point(int x, int y, int id, int isRestaurant)
  {
    this -> x = x;
    this -> y = y;
    this -> id = id;
    this -> isRestaurant = isRestaurant;
  }
  
  bool operator < (Point u) const
  {
    if (x != u.x) return x < u.x;
    if (y != u.y) return y < u.y;
    return isRestaurant < u.isRestaurant;
  }
};

int w, h, m, n, maxDist[100100], tree[200100];
vector <Point> p;
map <int,int> Y;

void add(int x, int v)
{
  for (int i = x + 1; i <= m + n; i += i & -i) tree[i] = min(tree[i], v);
}

int get(int x)
{
  int res = oo;
  for (int i = x + 1; i; i -= i & -i) res = min(res, tree[i]);
  return res;
}

void init()
{
  Y.clear();
  for (int i = 0; i < m + n; i++) Y[p[i].y] = 0;
  int id = 0;
  for (map <int,int>::iterator it = Y.begin(); it != Y.end(); it++)
    it -> second = id++;
    
  for (int i = 0; i <= m + n; i++) tree[i] = oo;
}

void solve()
{
  init();  
  sort(p.begin(), p.end());
  for (int i = 0; i < m + n; i++)
  {
    int yUnique = Y[p[i].y];
    if (p[i].isRestaurant) 
      maxDist[p[i].id] = max(maxDist[p[i].id], p[i].x + p[i].y - get(yUnique));
    else 
      add(yUnique, p[i].x + p[i].y);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  int x, y;
  cin >> w >> h >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    p.push_back(Point(x, y, i, 0));
    Y[y] = 0;
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    p.push_back(Point(x, y, i + 1, 1));
    Y[y] = 0;
  }
  
  solve();
  for (int i = 0; i < m + n; i++) p[i].x = w - p[i].x + 1;
  solve();
  for (int i = 0; i < m + n; i++) p[i].y = h - p[i].y + 1;
  solve();
  for (int i = 0; i < m + n; i++) p[i].x = w - p[i].x + 1;
  solve();
  
  int ans = oo, bestId = -1;
  for (int i = 1; i <= m; i++)
    if (maxDist[i] < ans)
    {
      ans = maxDist[i];
      bestId = i;
    }
    
  cout << ans << endl << bestId << endl;      
}