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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	while (k--)
	{
		int ta, fa, tb, fb;
		cin >> ta >> fa >> tb >> fb;
		if (ta == tb)
		{
			cout << abs(fa - fb) << '\n';
			continue;
		}
		if (fa < a && fb < a)
		{
			cout << a - fa + a - fb + abs(tb - ta) << '\n';
			continue;
		}
		if (fa > b && fb > b)
		{
			cout << fa - b + fb - b + abs(tb - ta) << '\n';
			continue;
		}
		cout << abs(ta - tb) + abs(fa - fb) << '\n';
	}
	return 0;
}