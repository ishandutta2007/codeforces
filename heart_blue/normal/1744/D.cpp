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
		scanf("%d", &n);
		int tot = n;
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			while (x % 2 == 0) x /= 2, tot--;
			int o = i;
			int cnt = 0;
			while (o % 2 == 0) o /= 2, cnt++;
			v.push_back(cnt);
		}
		sort(v.rbegin(), v.rend());
		int ans = 0;
		for (auto& x : v)
		{
			if (tot <= 0) break;
			tot -= x;
			ans++;
		}
		if (tot > 0) ans = -1;
		printf("%d\n", ans);

	}
	return 0;
}