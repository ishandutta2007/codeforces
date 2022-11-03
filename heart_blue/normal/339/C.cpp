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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int dp[N][22][11];
pair<int,int> pre[N][22][11];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(pre[0], -1);
	MEM(dp, 0);
	string s;
	int k;
	cin >> s >> k;
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1') v.push_back(i + 1);
	}
	dp[0][10][0] = 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (auto &x: v)
			{
				if (dp[i][j][x] == 0) continue;
				for (auto &y : v)
				{
					if (x == y) continue;
					if (j <= 10 && j + y > 10) dp[i + 1][j + y][y] = 1, pre[i + 1][j + y][y] = { j,x };
					if (j > 10 && j - y < 10) dp[i + 1][j - y][y] = 1, pre[i + 1][j - y][y] = { j,x };
				}
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (dp[k][i][j])
			{
				while (k--)
				{
					ans.push_back(j);
					tie(i, j) = pre[k + 1][i][j];
				}
				reverse(ans.begin(), ans.end());
				cout << "YES" << endl;
				for (auto &x : ans) cout << x << ' ';
				return 0;
			}
		}
	}
	cout << "NO" << endl;

	return 0;
}