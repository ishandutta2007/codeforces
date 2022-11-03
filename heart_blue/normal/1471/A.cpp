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
const int N = 5e3 + 10;
void build(map<int, int>& mc)
{
	string str;
	getline(cin, str);
	stringstream sin(str);
	int x;
	while (sin >> x)
	{
		mc[x] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, x;
		scanf("%d%d", &n, &x);
		LL tot = 0;
		LL maxv = 0;
		LL minv = 0;
		for (int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			maxv += (a + x - 1) / x;
			tot += a;
		}
		minv = (tot + x - 1) / x;
		printf("%lld %lld\n", minv, maxv);
	}
	return 0;
}