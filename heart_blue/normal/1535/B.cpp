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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
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
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x & 1) v.push_back(x);
		}
		int rest = (n - v.size());
		int ans = rest * v.size();
		ans += rest * (rest - 1) / 2;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				if (gcd(v[i], v[j]) > 1)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}