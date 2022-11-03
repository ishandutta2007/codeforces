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
const int N = 2e5 + 10;
int cnt[N];
int a[N];
vector<int> v;
void init(int k)
{
	cnt[0] = 0;
	for (int i = 1; i < N; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
		if (cnt[i] == k) v.push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	init(k);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	if (k == 0)
	{
		LL ans = 0;
		for (int i = 0; i < N; i++)
		{
			ans += 1LL * a[i] * (a[i] - 1) / 2;
		}
		cout << ans << endl;
		return 0;
	}
	LL ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == 0) continue;
		for (auto &x : v)
		{
			if ((i^x) < N) ans += 1LL * a[i] * a[i^x];
		}
	}
	cout << ans / 2 << endl;
	return 0;
}