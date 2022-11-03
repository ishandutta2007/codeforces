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
const int N = 5e2 + 10;
int rest[N];
int ans[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);		
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &ans[i][i]);
		rest[i] = i - 1;
	}
	for (int i = 1; i < n; i++)
	{
		int x = i, y = 1;
		vector<int> v;
		while (x <= n && y <= n)
		{
			v.push_back(ans[x][y]);
			if (rest[v.back()] == 0)
				v.pop_back();
			x++, y++;
		}
		x = i + 1, y = 1;
		for (auto& val : v)
			rest[val]--;
		reverse(v.begin(), v.end());
		while (x <= n && y <= n)
		{
			ans[x][y] = v.back();
			v.pop_back();
			x++, y++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d ", ans[i][j]);
		}
		puts("");
	}
	return 0;
}