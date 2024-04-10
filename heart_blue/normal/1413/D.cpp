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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> vp;
	for (int i = 1; i <= 2 * n; i++)
	{
		char op;
		scanf(" %c", &op);
		if (op == '+')
		{
			vp.emplace_back(0);
		}
		else
		{
			int x;
			scanf("%d", &x);
			vp.emplace_back(x);
		}
	}
	reverse(vp.begin(), vp.end());
	int cur = n;
	set<int> s;
	for (auto& x : vp)
	{
		if (x == 0)
		{
			if (s.empty()) puts("NO"), exit(0);
			ans[cur--] = *s.begin();
			s.erase(*s.begin());
		}
		else
		{
			s.insert(x);
		}
	}
	s.clear();
	reverse(vp.begin(), vp.end());
	cur = 1;
	for (auto& x : vp)
	{
		if (x == 0)
		{
			s.insert(ans[cur++]);
		}
		else
		{
			if (*s.begin() != x) puts("NO"), exit(0);
			s.erase(*s.begin());
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}