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
const int N = 2e2 + 10;
int cnt[N];
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
		int n, k;
		scanf("%d%d", &n, &k);
		string str;
		cin >> str;
		MEM(cnt, 0);
		for (auto& c : str)
			cnt[c]++;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int g = gcd(i, k);
			int r = i / g;
			int tot = 0;
			for (int j = 'a'; j <= 'z'; j++)
				tot += cnt[j] / r;
			if (tot >= g)
				ans = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}