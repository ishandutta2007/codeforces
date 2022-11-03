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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = INF;
	for (int i = 1; i + 1 <= n; i++)
	{
		int lsum = 0;
		vector<int> v1;
		for (int j = 0; j < 32; j++)
		{
			if (i - j <= 0) break;
			lsum ^= a[i - j];
			v1.push_back(lsum);
		}
		int rsum = 0;
		vector<int> v2;
		for (int j = 1; j <= 32; j++)
		{
			if (i + j > n) break;
			rsum ^= a[i + j];
			v2.push_back(rsum);
		}
		for (int j = 0; j < v1.size(); j++)
		{
			for (int k = 0; k < v2.size(); k++)
			{
				if (v1[j] > v2[k])
				{
					ans = min(ans, j + k);
				}
			}
		}
	}
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}