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
const int N = 4e5 + 10;
int a[N];
int flag[N];
int cnt[N];
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
		MEM(cnt, 0);
		MEM(flag, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		int cur = 1;
		vector<int> ans;
		while (cur <= n)
		{
			if (cnt[0] == 0)
			{
				while (cur <= n) ans.push_back(0), cur++;
				break;
			}
			int key = 0;
			for (int i = 0; i <= n; i++)
			{
				if (cnt[i])
					key = i;
				else
					break;
			}
			fill(flag, flag + key + 1, 0);
			int tot = 0;
			while (cur <= n)
			{
				int x = a[cur++];
				cnt[x]--;
				if (flag[x] == 0 && x <= key)
					flag[x] = 1, tot++;
				if (tot == key + 1) break;
			}
			ans.push_back(key + 1);
		}
		printf("%d\n", ans.size());
		for (auto& x : ans)
			printf("%d ", x);
		puts("");
	}
	return 0;
}