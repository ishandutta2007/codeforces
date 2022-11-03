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
const int N = 1e4 + 10;
int ans[N];
int ask(int a, int b, int c)
{
	cout << "? " << a << ' ' << b << ' ' << c << endl;
	int ret;
	cin >> ret;
	return ret;
}
pair<int, int> solve(int a, int b, int c, int d, int e, int f)
{
	int v1[] = { ask(a,b,d),ask(a,b,e),ask(a,b,f) };
	if (v1[0] == 0 && v1[1] == 0 && v1[2] == 0)
	{
		ans[a] = 0;
		ans[b] = 0;
		if (ask(a, d, e))
		{
			ans[d] = ans[e] = 1;
			return { a,d };
		}
		else if (ask(a, d, f))
		{
			ans[d] = ans[f] = 1;
			return { a,d };
		}
		else
		{
			ans[e] = ans[f] = 1;
			return { a,e };
		}
	}
	if (v1[1] == 1) d = e;
	else if (v1[2] == 1) d = f;
	ans[d] = 1;
	if (ask(a, c, d) == 0)
	{
		ans[a] = ans[c] = 0;
		ans[b] = 1;
		return { a,d };
	}
	else
	{
		ans[b] = ans[c] = 0;
		ans[a] = 1;
		return { b,d };
	}
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
		fill(ans + 1, ans + n + 1, -1);
		int key[2] = { -1,-1 };
		for (int i = 0; i * 3 <= n; i++)
		{
			int a = i * 3 + 1;
			int b = i * 3 + 2;
			int c = i * 3 + 3;
			if (ask(a, b, c) == 0) key[0] = i;
			else key[1] = i;
			if (key[0] != -1 && key[1] != -1) break;
		}
		auto [x, y] = solve(key[0] * 3 + 1, key[0] * 3 + 2, key[0] * 3 + 3,
			key[1] * 3 + 1, key[1] * 3 + 2, key[1] * 3 + 3);
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			if (ans[i] == -1)
			{
				ans[i] = ask(x, y, i);
			}
			if (ans[i] == 0)
				v.push_back(i);
		}
		cout << "! " << v.size();
		for (auto& x : v)
			cout << ' ' << x;
		cout << endl;

	}
	return 0;
}