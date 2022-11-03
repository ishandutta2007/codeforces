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
void add(int x)
{
	cnt[x]++;
}
void del(int x)
{
	if (x == 0) return;
	if (cnt[x]-- == 1) cnt.erase(x);
}
void check(int x)
{
	del(x);
	add(x + 1);
}
bool getans(map<int, int>& mc)
{
	if (mc.size() > 2) return false;
	if (mc.size() == 1)
	{
		auto p = *mc.begin();
		int x, tot;
		tie(x, tot) = p;
		if (x == 1) return true;
		if (tot == 1) return true;
	}
	else
	{
		int x, cnt1;
		int y, cnt2;
		tie(x, cnt1) = *mc.begin();
		tie(y, cnt2) = *mc.rbegin();
		if (x == 1 && cnt1 == 1) return true;
		if (x + 1 == y && cnt2 == 1) return true;
	}
	return false;
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mc;
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		check(mc[x]++);
		if (getans(cnt))
			ans = i;
	}
	cout << ans << endl;
	return 0;
}