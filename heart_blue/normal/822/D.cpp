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
const int N = 5e6 + 10;
LL ans[N];
void init()
{
	for (int i = 2; i < N; i++)
	{
		ans[i] = 1LL * i*(i - 1) / 2;
	}
	for (int i = 2; i < N; i++)
	{
		for (int j = i + i; j < N; j += i)
		{
			if (j / i > i) break;
			int d = j / i;
			ans[j] = min(ans[j], ans[j / i] + 1LL * j*(i - 1) / 2);
			ans[j] = min(ans[j], ans[j / d] + 1LL * j*(d - 1) / 2);
		}
	}
	for (int i = 1; i < N; i++) ans[i] %= INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*
	f(n/d)+n*(d-1)/2*n
	*/
	init();
	LL t, l, r;
	cin >> t >> l >> r;
	LL cur = 1;
	LL res = 0;
	for (int i = l; i <= r; i++)
	{
		res += cur*ans[i] % INF;
		if (res >= INF) res -= INF;
		cur = cur*t%INF;
	}
	cout << res << endl;
	return 0;
}