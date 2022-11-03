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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
map<int, int> mc;
map<int, int> mc2;
void error()
{
	puts("-1");
	exit(0);
}
void add(int x)
{
	if (mc2.count(x)) error();
	if (mc.count(x)) error();
	mc[x]++;
	mc2[x] = 1;
}
void del(int x)
{
	if (!mc.count(x)) error();
	mc.erase(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> ans;
	int pre = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x > 0) add(x);
		else del(-x);
		if (mc.empty())
		{
			ans.push_back(i - pre);
			pre = i;
			mc2.clear();
		}
	}
	if (!mc.empty()) error();
	printf("%d\n", ans.size());
	for (auto &x : ans)
		printf("%d ", x);
	return 0;
}