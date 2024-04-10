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
map<int, int> cnt;
int a[N];
void add(map<int, int>& mc, int x)
{
	mc[x]++;
}
void del(map<int, int>& mc, int x)
{
	mc[x]--;
	if (mc[x] <= 0)
		mc.erase(x);
}
void add(int x)
{
	del(cnt, a[x]);
	a[x]++;
	add(cnt, a[x]);
}
void del(int x)
{
	del(cnt, a[x]);
	a[x]--;
	add(cnt, a[x]);
}
bool check()
{
	vector<int> v;
	for (auto iter = cnt.rbegin(); iter != cnt.rend() && v.size() < 3; iter++)
	{
		if (iter->first <= 1) break;
		int tot = iter->second;
		while (tot-- && v.size() < 3) v.push_back(iter->first);
	}
	if (v.empty()) return false;
	if (v[0] >= 8) return true;
	if (v[0] < 4) return false;
	v[0] -= 4;
	sort(v.rbegin(), v.rend());
	while (!v.empty() && v.back() <= 1) v.pop_back();
	if (!v.empty() && v[0] >= 4) return true;
	return v.size() >= 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		add(x);
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		char op;
		int x;
		scanf(" %c%d", &op, &x);
		if (op == '+') add(x);
		else del(x);
		if (check()) puts("YES");
		else puts("NO");
	}
	return 0;
}