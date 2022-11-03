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
const int N = 3e2 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	cin >> k;
	//if (k == 1)
	//{
	//	puts("YES");
	//	puts("2 1");
	//	puts("1 2");
	//	return 0;
	//}
	if (k % 2 == 0)
	{
		puts("NO");
		return 0;
	}
	int n = k * 2 - 1;
	puts("YES");
	printf("%d %d\n", n * 2, n*k);
	vector<pair<int, int>> vp;
	for (int i = 1; i * 2 < k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			vp.push_back({ j,(j + i - 1) % n + 1 });
		}
	}
	for (int i = 2; i <= n / 2 + 1; i++)
	{
		vp.push_back({ i,i + n / 2 });
	}
	printf("%d %d\n", 1, n + 1);
	for (auto &p : vp)
	{
		printf("%d %d\n", p.first, p.second);
		printf("%d %d\n", p.first + n, p.second + n);
	}
	return 0;
}