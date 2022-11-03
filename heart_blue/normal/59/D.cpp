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
const int N = 3e5 + 10;
int a[N];
int pos[N];
vector<tuple<int, int, int>> vp;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 3 * n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	vp.resize(n);
	for (auto& [a, b, c] : vp)
	{
		scanf("%d%d%d", &a, &b, &c);
	}
	int k;
	scanf("%d", &k);
	vector<int> ans;
	for (auto [a, b, c] : vp)
	{
		flag[a] = flag[b] = flag[c] = 1;
		if (a != k && b != k && c != k) continue;
		if (a != k) swap(a, b);
		if (a != k) swap(a, c);
		if (pos[a] > min(pos[b], pos[c]))
		{
			for (int i = 1; i <= 3 * n; i++)
			{
				if (i == k) continue;
				ans.push_back(i);
			}
			break;
		}
		if (b > c) swap(b, c);
		flag[a] = flag[b] = flag[c] = 2;
		for (int i = 1; i <= c; i++)
		{
			if (i == a) continue;
			if (flag[i])
				ans.push_back(i);
		}
		for (int i = 1; i <= c; i++)
		{
			if (i == a) continue;
			if (flag[i] == 0)
				ans.push_back(i);
		}
		for (int i = c + 1; i <= n * 3; i++)
		{
			if (i == a) continue;
			ans.push_back(i);
		}
		break;
	}
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}