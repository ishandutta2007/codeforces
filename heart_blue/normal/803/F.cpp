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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v[N];
int p2[N];
int cnt[N];
int mu[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		mu[i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
		{
			v[j].push_back(i);
		}
		if (v[i].size() != 2) continue;
		for (int j = i; j < N; j += i)
		{
			mu[j] *= -1;
			if (j / i % i == 0) mu[j] = 0;
		}
	}
	p2[0] = 1;
	for (int i = 1; i < N; i++)
	{
		p2[i] = p2[i - 1] * 2 % INF;
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		for (auto& d : v[x])
			cnt[d]++;
	}
	LL ans = 0;
	for (int i = 1; i < N; i++)
	{
		ans += (p2[cnt[i]] - 1) * mu[i] % INF;
	}
	ans %= INF;
	if (ans < 0) ans += INF;
	printf("%lld\n", ans);
	return 0;
}