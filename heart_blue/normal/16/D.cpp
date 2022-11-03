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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n;
	getline(cin, str);
	int pre = INF;
	int ans = 0;
	int cnt = 0;
	while (n--)
	{
		getline(cin, str);
		for (auto& c : str)
		{
			if (!isalnum(c))
				c = ' ';
		}
		stringstream sin(str);
		int h, m;
		char o;
		sin >> h >> m >> o;
		h %= 12;
		int cur = h * 60 + m;
		if (o == 'p') cur += 12 * 60;
		if (cur < pre) ans++, cnt = 1;
		else if (cur == pre)
		{
			if (++cnt > 10) ans++, cnt -= 10;
		}
		else cnt = 1;
		pre = cur;
	}
	printf("%d\n", ans);
	return 0;
}