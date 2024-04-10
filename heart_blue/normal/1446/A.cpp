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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		LL tot;
		cin >> n >> tot;
		int ok = 0;
		LL sum = 0;
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (ok) continue;
			if (x > tot) continue;
			if (x >= (tot + 1) / 2)
			{
				puts("1");
				printf("%d\n", i);
				ok = 1;
			}
			else
			{
				v.push_back(i);
				sum += x;
				if (sum >= (tot + 1) / 2)
				{
					ok = 1;
					printf("%d\n", v.size());
					for (auto& x : v)
						printf("%d ", x);
					puts("");
				}
			}
		}
		if (ok == 0) puts("-1");
	}
	return 0;
}