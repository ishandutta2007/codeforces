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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int flag[N];
int b[N];
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
		vector<int> ans;
		MEM(flag, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			flag[b[i]] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			int x = b[i];
			ans.push_back(x);
			for (int j = x + 1; j <= 2 * n; j++)
			{
				if (flag[j]) continue;
				ans.push_back(j);
				flag[j] = 1;
				break;
			}
		}
		if (ans.size() != 2 * n) puts("-1");
		else
		{
			for (auto& x : ans)
				printf("%d ", x);
			puts("");
		}
	}
	return 0;
}