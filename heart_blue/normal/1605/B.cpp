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
const int N = 1e3 + 10;
char str[N];
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
		scanf("%s", str + 1);
		int cnt = count(str + 1, str + n + 1, '0');
		vector<int> ans;
		for (int i = 1; i <= n; i++)
		{
			if (i <= cnt && str[i] == '1') ans.push_back(i);
			if (i > cnt && str[i] == '0') ans.push_back(i);
		}
		if (ans.empty()) puts("0");
		else
		{
			puts("1");
			printf("%d", ans.size());
			for (auto& x : ans)
				printf(" %d", x);
			puts("");
		}
	}
	return 0;
}