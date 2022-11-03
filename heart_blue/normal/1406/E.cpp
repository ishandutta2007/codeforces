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
const int N = 1e5 + 10;
int flag[N];
int f[N];
int n, x;
int query(int op, int a)
{
	{
		int ret;
		cin >> ret;
		return ret;
	}
	//int ret = 0;
	//for (int i = a; i <= n; i += a)
	//{
	//	ret += f[i] ^ 1;
	//	if (op == 2 && i != x)
	//	{
	//		f[i] = 1;
	//	}
	//}
	//return ret;
}
int ask(int op, int a)
{
	cout << char(op - 1 + 'A') << ' ' << a << endl;
	if (op == 3)
	{
		exit(0);
	}
	return query(op, a);
}
void solve(int n)
{
	int ans = 1;
	vector<int> v;
	for (int i = 2; i <= n; i++)
	{
		if (flag[i]) continue;
		for (int j = i + i; j < N; j += i)
			flag[j] = 1;
		if (1LL * i * i <= n)
		{
			ask(2, i);
			int cnt = ask(1, i);
			if (cnt == 0) continue;
			int l = 2;
			int r = 0;
			for (LL j = i; j <= n / ans; j *= i) r++;
			int key = i;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				int cur = 1;
				for (int j = 0; j < mid; j++) cur *= i;
				if (ask(1, cur)) key = cur, l = mid + 1;
				else r = mid - 1;
			}
			ans *= key;
		}
		else
		{
			v.push_back(i);
		}
	}
	int step = 100;
	int l = 0, r = step;
	int cur = ask(1, 1);
	while (l < v.size())
	{
		r = min(r, int(v.size()));
		int tot = 0;
		for (int i = l; i < r; i++)
		{
			tot += ask(2, v[i]);
		}
		int cnt = ask(1, 1);
		if (cur - cnt != tot)
		{
			for (int i = l; i < r; i++)
			{
				if (ask(1, v[i]))
				{
					ans *= v[i];
					break;
				}
			}
			break;
		}
		cur = cnt;
		l += step, r += step;
	}
	ask(3, ans);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	solve(n);
	return 0;
}