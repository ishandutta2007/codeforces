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
const int N = 1e3 + 10;
int a[N];
bool check(vector<int> v1, vector<int> v2)
{
	swap(v2[1], v2[2]);
	return v1 == v2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int flag = 0;
		vector<vector<int>> vp(n);
		for (auto& v : vp)
		{
			v.resize(4);
			for (auto& x : v) scanf("%d", &x);
		}
		if (m & 1)
		{
			puts("NO");
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (check(vp[i], vp[j]))
					flag |= 1;
			}
			if (check(vp[i], vp[i]))
				flag |= 2;
		}
		if (flag == 3) puts("YES");
		else puts("NO");
	}
	return 0;
}