#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
vector<pair<int, int>> vp[N*N];
vector<pair<int, int>> vp0[N*N];
vector<int> v[N*N];
int dp[N][N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, p;
	cin >> n >> m >> p;
	MEM(dp, 0x1f);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			vp[x].push_back({ j, i });
			vp0[x].push_back({ i,j });
			if (x == 1)
			{
				dp[i][j] = i + j;
			}
		}
	}
	for (int i = 1; i <= p; i++) sort(vp[i].begin(), vp[i].end());
	for (int i = 1; i <= p; i++)
	{
		v[i].push_back(0);
		for (int j = 1; j < vp0[i].size(); j++)
		{
			if (vp0[i][j].first != vp0[i][j - 1].first)
			{
				v[i].push_back(j);
			}
		}
		v[i].push_back(vp0[i].size());
	}
	for (int i = 2; i <= p; i++)
	{
		
		for (int j = 0; j < v[i-1].size() - 1; j++)
		{
			int s = v[i - 1][j];
			int t = v[i - 1][j + 1];
			int row = vp0[i - 1][s].first;
			for (int k = s; k < t; k++)
			{
				int k0 = vp0[i - 1][k].second;
				dp[row][k0] -= k0;
			}
			
			int key = -1;
			int minv = INF;
			int s0 = s;
			for (auto &pp : vp[i])
			{
				while (s0 < t && pp.first >= vp0[i - 1][s0].second)
				{
					int k0 = vp0[i - 1][s0].second;
					if (dp[row][k0] < minv)
					{
						minv = dp[row][k0];
						key = k0;
					}
					s0++;
				}
				if (key == -1) continue;
				int x, y;
				tie(y, x) = pp;
				dp[x][y] = min(dp[x][y], abs(x - row) + minv + y);
			}
			for (int k = s; k < t; k++)
			{
				int k0 = vp0[i - 1][k].second;
				dp[row][k0] += k0;
				dp[row][k0] += k0;
			}
			s0 = t - 1;
			minv = INF;
			key = -1;
			for (int ii = vp[i].size() - 1; ii >= 0; ii--)
			{
				while (s0 >= s && vp[i][ii].first <= vp0[i - 1][s0].second)
				{
					int k0 = vp0[i - 1][s0].second;
					if (dp[row][k0] < minv)
					{
						minv = dp[row][k0];
						key = k0;
					}
					s0--;
				}
				if (key == -1) continue;
				int x, y;
				tie(y, x) = vp[i][ii];
				dp[x][y] = min(dp[x][y], abs(x - row) + minv - y);
			}
			for (int k = s; k < t; k++)
			{
				int k0 = vp0[i - 1][k].second;
				dp[row][k0] -= k0;
			}
		}
	}
	int ans = 0;
	int x, y;
	tie(y, x) = vp[p][0];
	cout << dp[x][y] << endl;
	return 0;
}