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
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int k;
	cin >> k;
	for (auto &c : str) a[c]++;
	vector<pair<int, int>> vp;
	for (int i = 0; i < N; i++)
	{
		if (a[i])
		{
			vp.push_back({ a[i],i });
		}
	}
	sort(vp.begin(), vp.end());
	int cnt = 0;
	for (auto &p : vp)
	{
		int y, x;
		tie(y, x) = p;
		int o = min(y, k);
		if (o != y) cnt++;
		k -= o;
		a[x] = o;
	}
	printf("%d\n", cnt);
	for (auto &c : str)
	{
		if (a[c]-- > 0) continue;
		putchar(c);
	}

	return 0;
}