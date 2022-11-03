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
	int a, b, x;
	cin >> a >> b >> x;
	string ans(x + 1, '0');
	for (int i = (a > b); i < ans.size(); i += 2) ans[i] = '1';
	for (auto &c : ans)
	{
		if (c == '0') a--;
		else b--;
	}
	for (auto &c : ans)
	{
		putchar(c);
		if (c == '0')
		{
			printf(string(a, '0').c_str());
			a = 0;
		}
		else
		{
			printf(string(b, '1').c_str());
			b = 0;
		}
	}
	return 0;
}