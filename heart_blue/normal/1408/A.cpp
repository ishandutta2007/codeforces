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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
int a[N][3];
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		for (int o = 0; o < 3; o++)
		{
			for (int i = 1; i <= n; i++)
				cin >> a[i][o];
		}
		vector<int> ans;
		ans.push_back(a[1][0]);
		for (int i = 2; i < n; i++)
		{
			for (int o = 0; o < 3; o++)
			{
				if (a[i][o] != ans.back())
				{
					ans.push_back(a[i][o]);
					break;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (a[n][i] == ans.back()) continue;
			if (a[n][i] == ans.front()) continue;
			ans.push_back(a[n][i]);
			break;
		}
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}