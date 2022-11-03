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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e6 + 10;
int a[200];
int ok[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		MEM(ok, 0);
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		map<int, int> mc;
		vector<int> ans;
		for (int i = 1; i < N && ans.size() <= n; i++)
		{
			int flag = 0;
			for (int j = 1; j <= n; j++)
			{
				if (ok[a[j] + i])
				{
					flag = 1;
					break;
				}
			}
			if (flag) continue;
			for (int j = 1; j <= n; j++)
			{
				ok[a[j] + i] = 1;
			}
			ans.push_back(i);
		}
		puts("YES");
		for (int i = 0; i < n; i++)
			printf("%d%c", ans[i], " \n"[i + 1 == n]);
	}
	return 0;
}