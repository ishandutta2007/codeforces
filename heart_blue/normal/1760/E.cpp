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
const int N = 1e3 + 10;
LL check(string& str)
{
	LL res = 0;
	int cnt = 0;
	for (auto& c : str)
	{
		if (c == '0') res += cnt;
		else cnt++;
	}
	return res;
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
		string str(n, '0');
		for (auto& c : str)
		{
			scanf(" %c", &c);
		}
		LL ans = check(str);
		int pos1 = str.find_first_of('0');
		int pos2 = str.find_last_of('1');
		vector<int> key = { pos1,pos2 };
		for (auto& pos : key)
		{
			if (pos != -1)
			{
				str[pos] ^= 1;
				ans = max(ans, check(str));
				str[pos] ^= 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}