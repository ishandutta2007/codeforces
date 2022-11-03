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
	LL x, d;
	LL o = 0x3fffffffLL;
	int cur = 30;
	LL s = 1;
	cin >> x >> d;
	vector<LL> ans;
	while (x)
	{
		int cnt = x / o;
		x %= o;
		while (cnt--)
		{
			for (int i = 0; i < cur; i++) ans.push_back(s);
			s += d;
		}
		cur--;
		o >>= 1;
	}
	printf("%d\n", ans.size());
	for (auto &x : ans) printf("%lld ", x);
	return 0;
}