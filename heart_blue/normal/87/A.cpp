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
const int N = 5e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<LL, int> mc;
	int a, b;
	cin >> a >> b;
	if (a < b)
	{
		for (LL i = 1; i <= b; i++) mc[i*a] = 0;
		for (LL i = 1; i <= a; i++) mc[i*b] = 1;
	}
	else
	{
		for (LL i = 1; i <= a; i++) mc[i*b] = 1;
		for (LL i = 1; i <= b; i++) mc[i*a] = 0;
	}
	LL pre = 0;
	LL sum[2] = { 0,0 };
	for (auto &p : mc)
	{
		sum[p.second] += p.first - pre;
		pre = p.first;
	}
	if (sum[0] > sum[1]) puts("Dasha");
	else if (sum[0] == sum[1]) puts("Equal");
	else puts("Masha");
	return 0;
}