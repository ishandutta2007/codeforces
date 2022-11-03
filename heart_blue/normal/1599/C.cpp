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
LL C(int n, int m)
{
	if (n < m) return 0;
	if (m == 0) return 1;
	if (m == 1) return n;
	if (m == 2) return n * (n - 1) / 2;
	if (m == 3) return n * (n - 1) * (n - 2) / 6;
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	while (str.length() < 6) str += '0';
	str.erase(str.find('.'), 1);
	LL u = stoi(str);
	LL d = 10000;
	for (int i = 0; i <= n; i++)
	{
		LL tot = 0;
		LL ok = 0;
		for (int o1 = 0; o1 <= 3; o1++)
		{
			if (o1 > i) continue;
			int j = n - i;
			int o2 = 3 - o1;
			if (o2 > j) continue;
			tot += C(i, o1) * C(j, o2);
			if (o1 >= 2) ok += 2 * C(i, o1) * C(j, o2);
			else if (o1 == 1) ok += C(i, o1) * C(j, o2);
		}
		tot *= 2;
		if (ok * d >= u * tot)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}