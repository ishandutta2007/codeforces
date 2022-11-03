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
const int N = 2e2 + 10;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> vp = { { 3, 1},{ 0, 0},{ 0, 1},{ 0, 2},{ 1, 0},{ 1, 1},{ 1, 2},{ 2, 0},{ 2, 1},{ 2, 2} }, vp2;
	map<pair<int, int>, int> mp;
	for (auto p : vp) mp[p] = 1;
	int n;
	cin >> n;
	while (n--)
	{
		char c;
		cin >> c;
		vp2.push_back(vp[c - '0']);
	}
	int tot = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int flag = 1;
			for (auto &p : vp2)
			{
				int x, y;
				tie(x, y) = p;
				x += i;
				y += j;
				if (!mp.count({ x,y }))
				{
					flag = 0;
					break;
				}
			}
			tot += flag;
		}
	}
	if (tot > 1) puts("NO");
	else puts("YES");
	return 0;
}