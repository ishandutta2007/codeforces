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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int sz[] = { (n + m - 1) / m ,n / m };
		int cnt[] = { n % m ,m - n % m };
		vector<int> key;
		while (k--)
		{
			for (int o = 0; o < 2; o++)
			{
				int c = cnt[o];
				while (c--) key.push_back(sz[o]);
			}
		}
		int cur = 1;
		int tot = 0;
		for (auto x : key)
		{
			printf("%d", x);
			tot += x;
			while (x--)
			{
				printf(" %d", cur++);
				if (cur > n) cur -= n;
			}
			if (tot == n)
			{
				tot = 0;
				cur -= n;
				cur += sz[0] * cnt[0];
				if (cur <= 0) cur += n;
			}
			puts("");
		}
		puts("");
	}
	return 0;
}