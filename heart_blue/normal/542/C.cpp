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
const int N = 2e2 + 10;
int flag[N];
int a[N];
int b[N];
int cnt[N];
int maxv[N];
void refrain(vector<int>& v)
{
	for (int i = 0; i + 1 < v.size(); i++)
	{
		v[i + 1] += v[i] / 10;
		v[i] %= 10;
	}
	while (v.back() > 10)
	{
		int x = v.back();
		v.push_back(x / 10);
		v[v.size() - 2] %= 10;
	}
}
void multy(vector<int>& v, int c)
{
	for (auto& x : v)
	{
		x *= c;
	}
	refrain(v);
}
void add(vector<int>& v, int c)
{
	v[0] += c;
	refrain(v);
}
bool check(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (b[b[i]] != b[i])
			return false;
	}
	return true;
}
void solve(int n)
{
	memcpy(b, a, sizeof(a));
	for (int o = 1; o < 2000; o++)
	{
		if (check(n))
		{
			printf("%d\n", o);
			exit(0);
		}
		for (int i = 1; i <= n; i++)
			b[i] = a[b[i]];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	solve(n);
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		MEM(flag, 0);
		int cur = i;
		while (flag[cur] < 2)
		{
			flag[cur]++;
			cur = a[cur];
		}
		int cnt1 = count(flag + 1, flag + n + 1, 1);
		int cnt2 = count(flag + 1, flag + n + 1, 2);
		v.push_back(cnt2);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto x : v)
	{
		for (int i = 2; i <= x; i++)
		{
			if (x % i) continue;
			int tot = 0;
			while (x % i == 0) x /= i, tot++;
			cnt[i] = max(cnt[i], tot);
		}
	}
	vector<int> ans;
	ans.push_back(1);
	for (int i = 2; i < N; i++)
	{
		if (cnt[i] == 0) continue;
		int x = 1;
		while (cnt[i]--) x *= i;
		multy(ans, x);
	}
	reverse(ans.begin(), ans.end());
	for (auto& x : ans)
		printf("%d", x);
	return 0;
}