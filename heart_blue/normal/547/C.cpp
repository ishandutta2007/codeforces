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
const int N = 5e5 + 10;
vector<int> v[N];
int mu[N];
int a[N];
int in[N];
int cnt[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i) v[j].push_back(i);
	}
	for (int i = 1; i < N; i++) mu[i] = 1;
	mu[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i; j < N; j += i)
		{
			a[j] = 1;
			mu[j] = -mu[j];
			if (j / i % i == 0) mu[j] = 0;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	LL ans = 0;
	while (q--)
	{
		int x;
		cin >> x;
		if (in[x])
		{
			for (auto &d : v[a[x]]) cnt[d]--;
		}
		LL t = 0;
		for (auto &d : v[a[x]]) t += mu[d] * cnt[d];
		if (in[x]) ans -= t;
		else ans += t;
		in[x] ^= 1;
		if (in[x])
		{
			for (auto &d : v[a[x]]) cnt[d]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}