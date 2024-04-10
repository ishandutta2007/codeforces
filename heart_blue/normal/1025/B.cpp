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
const int MOD = 998244353;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
pair<int, int> vp[N];
vector<int> v;
void check(int x)
{
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i) continue;
		v.push_back(i);
		while (x%i == 0) x /= i;
	}
	if (x > 1) v.push_back(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp[i] = { x,y };
	}
	check(vp[1].first);
	check(vp[1].second);
	int ans = -1;
	for (auto &x : v)
	{
		for (int i = 2; i <= n; i++)
		{
			if (vp[i].first %x && vp[i].second%x)
			{
				x = -1;
				break;
			}
		}
		if (x != -1)
		{
			printf("%d\n", x);
			return 0;
		}
	}
	puts("-1");
	return 0;
}