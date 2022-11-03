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
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k;
	cin >> n >> k;
	if (n*(n - 1) / 2 < k)
	{
		puts("Impossible");
		return 0;
	}
	vector<int> v;
	putchar('(');
	int o = 1;
	while (k >= o)
	{
		v.push_back(o);
		k -= o++;
	}
	if (k) v.push_back(k);
	sort(v.begin(), v.end());
	n--;
	int cost = 1;
	for (int i = 0; i < v.size(); i++)
	{
		if (i > 0 && v[i] == v[i - 1]) printf(")"),cost--;
		{
			putchar('(');
			cost++;
			n--;
		}
	}
	while (cost--) putchar(')');
	while (n-- > 0) printf("()");

	return 0;
}