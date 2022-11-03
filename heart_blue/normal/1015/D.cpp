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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k, s;
	cin >> n >> k >> s;
	if (k > s || (n - 1)*k < s)
	{
		puts("NO");
		return 0;
	}
	int x = s / k;
	int y = s / k + 1;
	int cnty = s % k;
	int cntx = k - cnty;
	int o = 1;
	int cur = 1;
	vector<int> v;
	for (int i = 1; i <= cnty; i++)
	{
		cur += o*y;
		o = -o;
		v.push_back(cur);
	}
	for (int i = 1; i <= cntx; i++)
	{
		cur += o * x;
		o = -o;
		v.push_back(cur);
	}
	puts("YES");
	for (auto &x : v) cout << x << ' ';
	return 0;
}