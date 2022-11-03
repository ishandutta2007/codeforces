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
const int N = 2e4 + 10;
vector<int> v[N];
int check(int x, int y, int o)
{
	if (x > y) swap(x, y);
	if (x == 0) return y;
	if (abs(x - o) > abs(y - o)) return y;
	else return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
			v[j].push_back(i);
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vector<int> v;
		for (int i = 1; i < 8; i++) v.push_back(i);
		int ans = 0;
		do
		{
			int cnt = 0;
			int vp[] = { a,b,c };
			for (auto& o : v)
			{
				int flag = 1;
				for (int i = 0; i < 3; i++)
				{
					if (o >> i & 1)
					{
						if (vp[i]-- == 0)
						{
							flag = 0;
							break;
						}
					}
				}
				if (flag == 0) break;
				cnt++;
			}
			ans = max(ans, cnt);
		} while (next_permutation(v.begin(), v.end()));
		printf("%d\n", ans);
	}
	return 0;
}