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
LL fact[20];
int flag[N];
int a[N];
void solve(int n, int k)
{
	MEM(flag, 0);
	k--;
	for (int i = 1; i <= n; i++)
	{
		int o = k / fact[n - i];
		k %= fact[n - i];
		for (int j = 1; j <= n; j++)
		{
			if (flag[j]) continue;
			if (o == 0)
			{
				flag[j] = 1;
				a[i] = j;
				break;
			}
			o--;
		}
	}
}
bool check(int n)
{
	while (n)
	{
		int x = n % 10;
		if (x != 4 && x != 7) return false;
		n /= 10;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	v.push_back(4);
	v.push_back(7);
	fact[0] = 1;
	for (int i = 1; i < 20; i++)
	{
		fact[i] = fact[i - 1] * i;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] * 10LL > INF) continue;
		v.push_back(v[i] * 10 + 4);
		v.push_back(v[i] * 10 + 7);
	}
	int n, k;
	cin >> n >> k;
	int sz = min(13, n);
	if (n <= 13)
	{
		if (fact[n] < k) puts("-1"), exit(0);
	}
	int ans = 0;
	for (auto& x : v)
	{
		if (x <= n - sz)
			ans++;
	}
	solve(sz, k);
	for (int i = 1; i <= sz; i++)
	{
		if (check(n - sz + i) && check(a[i] + n - sz))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}