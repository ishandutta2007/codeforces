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
const int N = 1e6 + 10;
vector<string> vs;
int nex[N][21];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, r, c;
	cin >> n >> r >> c;
	vs.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}
	int ptr = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		while (ptr < n && sum + max(0, ptr - i) + vs[ptr].length() <= c)
		{
			sum += vs[ptr++].length();
		}
		nex[i][0] = ptr - 1;
		sum -= vs[i].length();
		ptr = max(ptr, i + 1);
		sum = max(sum, 0);
	}
	nex[n][0] = n - 1;
	for (int o = 1; o < 21; o++)
	{
		for (int i = 0; i <= n; i++)
		{
			nex[i][o] = nex[nex[i][o - 1] + 1][o - 1];
		}
	}
	pair<int, int> ans;
	for (int i = 0; i < n; i++)
	{
		int cur = i;
		for (int o = 0; (1 << o) <= r; o++)
		{
			if (r >> o & 1)
			{
				cur = nex[cur][o] + 1;
			}
		}
		ans = max(ans, { cur - i,i });
	}
	int cur = ans.second;
	while (r--)
	{
		if (cur > nex[cur][0]) break;
		int ed = nex[cur][0];
		for (int i = cur; i <= ed; i++) printf("%s%c", vs[i].c_str(), " \n"[i == ed]);
		cur = nex[cur][0] + 1;
	}

	return 0;
}