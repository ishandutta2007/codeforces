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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);		
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		if (n % 2050)
		{
			puts("-1");
			continue;
		}
		string str = to_string(n / 2050);
		int ans = 0;
		for (auto& c : str)
			ans += c - '0';
		printf("%d\n", ans);
	}
	return 0;
}