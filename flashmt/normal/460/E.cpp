#include <bits/stdc++.h>
using namespace std;

int k, r, ans;
vector < pair<int,int> > candidates, points, bestPoints;

int sqr(int x)
{
  return x * x;
}

void att(int i, int sum, int last)
{
  if ((k - i) * (k - 1 + i) / 2 * r * r * 4 + sum <= ans) return;
  
  if (i == k)
  {
    if (sum > ans)
    {
      ans = sum;
      bestPoints = points;
    }
    return;
  }
  
  for (int j = last; j < (k == 7 && i < 3 ? 4 : int(candidates.size())); j++)
  {
    int newSum = sum;
    for (int p = 0; p < i; p++)
      newSum += sqr(candidates[j].first - points[p].first) + sqr(candidates[j].second - points[p].second);
    points.push_back(candidates[j]);
    att(i + 1, newSum, j);
    points.pop_back();
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> k >> r;
  
  candidates.push_back(make_pair(0, r));
  candidates.push_back(make_pair(r, 0));
  candidates.push_back(make_pair(0, -r));
  candidates.push_back(make_pair(-r, 0));
  
  vector < pair < int, pair<int,int> > > a;
  for (int x = 1; x < r; x++)
    if (x > 0)  
      for (int y = r; y > 0; y--)
        if (x * x + y * y <= r * r)
        {
          if (k != 8 && k != 6)
          {
            candidates.push_back(make_pair(x, y));
            candidates.push_back(make_pair(x, -y));
            candidates.push_back(make_pair(-x, y));
            candidates.push_back(make_pair(-x, -y));
          }
          break;
        }
  
  att(0, 0, 0);
  cout << ans << endl;
  for (int i = 0; i < k; i++) 
    cout << bestPoints[i].first << ' ' << bestPoints[i].second << endl;
}