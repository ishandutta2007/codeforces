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
const int N = 2e5 + 20;

int a[N];
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		vector<int> ans;
		for (int o = n; o >= 1; o--)
		{
			int pos = 0;
			for (int i = 1; i <= o; i++)
			{
				if (a[i] == o)
				{
					pos = i;
				}
			}
			if (pos == o)
			{
				ans.push_back(0);
				continue;
			}
			ans.push_back(pos);
			for (int i = o; i >= 1; i--)
			{
				b[i] = a[pos--];
				if (pos == 0) pos = o;
			}
			for (int i = 1; i <= o; i++)
				a[i] = b[i];
		}
		reverse(ans.begin(), ans.end());
		for (auto& x : ans)
			printf("%d ", x);
		puts("");
	}
	return 0;
}