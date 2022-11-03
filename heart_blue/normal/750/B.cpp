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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int k = 20000;
	int cur = 0;
	cin >> n;
	int flag = 1;
	while (n--)
	{
		string str;
		int x;
		cin >> x >> str;
		if (cur == 0 && str != "South")
		{
			flag = 0;
			break;
		}
		if (cur == k && str != "North")
		{
			flag = 0;
			break;
		}
		if (str == "South") cur += x;
		if (str == "North") cur -= x;
		if (cur < 0 || cur > k)
		{
			flag = 0;
			break;
		}
	}
	if (cur != 0) flag = 0;
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}