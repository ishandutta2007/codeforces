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
const int N = 2e5 + 10;
int check(vector<int> v1, int pos, int x)
{
	vector<int> v2 = v1;
	if (pos != -1)
		v2[pos] = x;
	sort(v2.begin(), v2.end());
	int cnt = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] == v2[i]) continue;
		if (v1[i] <= x) return INF;
		cnt++;
		swap(v1[i], x);
	}
	if (v1 == v2) return cnt;
	else return INF;
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
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		int ans = check(v, -1, x);
		for (int i = 0; i < v.size(); i++)
		{
			ans = min(ans, check(v, i, x));
		}
		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}