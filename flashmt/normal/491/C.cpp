#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct MinCostMatching
{
	int m, n;
	vector <int> leftDelta, rightDelta, leftMatch, rightMatch, minRight;
	vector <int> prev, seen;
	vector < vector <int> > a;
	
	MinCostMatching() {}
	MinCostMatching(int m, int n)
	{
		this -> m = m;
		this -> n = n;
		leftDelta = rightMatch = vector <int>(m + 1, 0);
		rightDelta = minRight = leftMatch = prev = seen = vector <int>(n + 1, 0);
		a = vector < vector <int> >(m + 1);
		for (int i = 0; i <= m; i++) a[i] = vector <int>(n + 1, oo - 1);
	}
	
	void addEdge(int x, int y, int cost)
	{
		a[x][y] = min(a[x][y], cost);
	}
	
	int minCost()
	{
		for (int i = 1; i <= m; i++)
		{
			leftMatch[0] = i;
			int y = 0;
			for (int j = 0; j <= n; j++) seen[j] = 0, minRight[j] = oo;
			
			do
			{
				seen[y] = 1;
				int x = leftMatch[y], delta = oo, yy;
				for (int j = 1; j <= n; j++)
					if (!seen[j])
					{
						int cur = a[x][j] - leftDelta[x] - rightDelta[j];
						if (cur < minRight[j]) minRight[j] = cur, prev[j] = y;
						if (minRight[j] < delta) delta = minRight[j], yy = j;
					}
				
				for (int j = 0; j <= n; j++)
					if (seen[j]) leftDelta[leftMatch[j]] += delta, rightDelta[j] -= delta;
					else minRight[j] -= delta;
				y = yy;
			} while (leftMatch[y]);
			
			do
			{
				int yy = prev[y];
				leftMatch[y] = leftMatch[yy];
				y = yy;
			} while (y);
		}
		
    for (int i = 1; i <= n; i++) rightMatch[leftMatch[i]] = i;
		return -rightDelta[0];
	}
};

int n, k, cnt[53][53];
string s, t;

int toInt(char c)
{
  return c <= 'Z' ? c - 'A' + 27 : c - 'a' + 1;
}

char toChar(int x)
{
  return x <= 26 ? char(x + 'a' - 1) : char(x + 'A' - 27);
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> k >> s >> t;
  for (int i = 0; i < n; i++) cnt[toInt(s[i])][toInt(t[i])]++;
  
  MinCostMatching mcm(k, k);
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++)
      mcm.addEdge(i, j, -cnt[i][j]);
  
  cout << -mcm.minCost() << endl;
  for (int i = 1; i <= k; i++) cout << toChar(mcm.rightMatch[i]);
}