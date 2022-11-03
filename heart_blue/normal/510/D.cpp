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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc[2];
	int o;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int cost;
		cin >> cost;
		o = i&1;
		mc[o] = mc[o ^ 1];
		if(!mc[o].count(a[i])) 
			mc[o][a[i]] = cost;
		mc[o][a[i]] = min(mc[o][a[i]], cost);
		for (auto &p : mc[o ^ 1])
		{
			int g = gcd(p.first, a[i]);
			int c = p.second + cost;
			if (!mc[o].count(g)) mc[o][g] = c;
			mc[o][g] = min(mc[o][g], c);
		}
	}
	if (mc[n & 1].count(1)) cout << mc[n & 1][1] << endl;
	else cout << -1 << endl;
	return 0;
}