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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int b[N];
int ans1[N];
int ans2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v1, v2;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			while (x % 10 != 2 && x % 10 != 0) x += x % 10;
			if (x % 10 == 2) v1.push_back(x);
			else v2.push_back(x);
		}
		if (!v1.empty() && !v2.empty())
		{
			puts("No");
			continue;
		}
		int flag = 1;
		if (!v1.empty())
		{
			sort(v1.begin(), v1.end());
			for (int i = 1; i < v1.size(); i++)
			{
				if ((v1[i] - v1[i - 1]) % 20)
					flag = 0;
			}
		}
		else
		{
			if (count(v2.begin(), v2.end(), v2[0]) != v2.size())
				flag = 0;
		}
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;
}