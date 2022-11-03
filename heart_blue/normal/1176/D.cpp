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
const int N = 3e6 + 10;
int a[N];
int p[N];
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i; j < N; j += i)
		{
			if (!a[j]) a[j] = i;
		}
		p[++k] = i;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	map<int, int> mc;
	int n;
	scanf("%d", &n);
	n *= 2;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		mc[x]++;
	}
	vector<int> ans;
	for (auto iter = mc.rbegin(); iter != mc.rend(); iter++)
	{
		int x = iter->first;
		int &cnt = iter->second;
		if (a[x] == x) continue;
		mc[x / a[x]] -= cnt;
		while (cnt--) ans.push_back(x);
		cnt = 0;
	}
	for (auto &p : mc)
	{
		int x, cnt;
		tie(x, cnt) = p;
		if (x != a[x]) continue;
		mc[::p[x]] -= cnt;
		while (cnt--) ans.push_back(x);
	}
	for (auto &x : ans) printf("%d ", x);
	return 0;
}