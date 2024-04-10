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
inline LL multy(LL a, LL b)
{
	if (a <= INF * INF / b) return a * b;
	else return INF * INF;
}


LL p[100];
LL p2[100];
vector<LL> v[100];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	p[0] = 1;
	for (int i = 1; i < 100; i++)
		p[i] = multy(9, p[i - 1]);
	p2[0] = 0;
	p2[1] = 1;
	for (int i = 2; i < 100; i++)
		p2[i] = multy(10, p2[i - 1]);

	int n;
	LL x;
	scanf("%d%lld", &n, &x);
	string s = to_string(x);
	if (*max_element(s.begin(), s.end()) == '1')
	{
		puts("-1");
		return 0;
	}
	int ans = 30;
	map<LL, int> mc;
	mc[x] = 0;
	v[0].push_back(x);
	for (int i = 0; i < ans; i++)
	{
		for (auto& val : v[i])
		{
			if (multy(val, p[ans - i]) < p2[n]) continue;
			if (to_string(val).length() == n)
			{
				ans = i;
				break;
			}
			string str = to_string(val);
			for (auto c : str)
			{
				c -= '0';
				if (c <= 1) continue;
				LL o = multy(c, val);
				if (mc.count(o)) continue;
				mc[o] = i + 1;
				v[i + 1].push_back(o);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}