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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> vd;
vector<int> vp;
int flag[N];
int p[N];
int k = 0;
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		p[k++] = i;
		for (int j = i + i; j < N; j += i)
			flag[j] = 1;
	}
}
void build(int n)
{
	vd.clear();
	vp.clear();
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		vd.push_back(i);
		if (i * i != n) vd.push_back(n / i);
	}
	vd.push_back(n);
	sort(vd.begin(), vd.end());
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		vp.push_back(i);
		while (n % i == 0)
			n /= i;
	}
	if (n > 1) vp.push_back(n);
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		build(n);
		if (vp.size() == 1)
		{
			for (auto& x : vd)
				printf("%d ", x);
			puts("");
			puts("0");
			continue;
		}
		if (vp.size() == 2)
		{
			int x = vp[0];
			int y = vp[1];
			int cnt = 0;
			vector<int> v12, v1, v2;
			for (auto& d : vd)
			{
				if (d % (x * y) == 0) v12.push_back(d), cnt++;
				else if (d % x == 0) v1.push_back(d);
				else v2.push_back(d);
			}
			for (auto& d : v1) printf("%d ", d);
			printf("%d ", v12.back());
			v12.pop_back();
			for (auto& d : v2) printf("%d ", d);
			for (auto& d : v12) printf("%d ", d);
			puts("");
			if (cnt == 1) puts("1");
			else puts("0");
			continue;
		}
		map<int, int> mc;
		for (int i = 1; i < vp.size(); i++)
		{
			int lcm = vp[i] / gcd(vp[i], vp[i - 1]) * vp[i - 1];
			mc[lcm] = 1;
			mc[vp[i - 1]] = 1;
			mc[vp[i]] = 1;
		}
		mc[vp.back() / gcd(vp.back(), vp.front()) * vp.front()] = 1;
		vector<int> ans;
		vp.push_back(vp[0]);
		for (int i = 0; i + 1 < vp.size(); i++)
		{
			ans.push_back(vp[i]);
			int lcm = vp[i] / gcd(vp[i], vp[i + 1]) * vp[i + 1];
			for (auto& d : vd)
			{
				if (d % vp[i] == 0 && !mc.count(d))
				{
					ans.push_back(d);
					mc[d] = 1;
				}
			}
			if(lcm != vp[i]) 
				ans.push_back(lcm);
		}
		for (int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
		int cnt = 0;
		ans.push_back(ans[0]);
		for (int i = 1; i < ans.size(); i++)
		{
			if (gcd(ans[i], ans[i - 1]) == 1)
				cnt++;
		}
		printf("%d\n", cnt++);
	}
	return 0;
}