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
const int N = 5e5 + 10;
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
		string str;
		cin >> str;
		if (count(str.begin(), str.end(), str[0]) == str.length())
		{
			printf("%d\n", n);
			continue;
		}
		int r = count(str.begin(), str.end(), 'R');
		int d = str.length() - r;
		r++;
		d++;
		LL tot = 1LL * n * n - 1LL * r * d + (str.length() + 1);
		int o = str.find_first_not_of(str[0]);
		if (str[0] == 'R') tot -= 1LL * o * (n - d);
		else tot -= 1LL * o * (n - r);
		printf("%lld\n", tot);
	}
	return 0;
}