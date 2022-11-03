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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v[N];
LL powmod(LL a, LL b, LL mod = INF)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
			v[j].push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	sort(a.begin(), a.end());
	int maxv = a.back();
	LL ans = 0;
	for (int i = 1; i <= maxv; i++)
	{
		int tot = a.end() - lower_bound(a.begin(), a.end(), i);
		LL o = powmod(v[i].size(), tot) - powmod(v[i].size() - 1, tot);
		for (int j = 0; j + 1 < v[i].size(); j++)
		{
			auto cnt = lower_bound(a.begin(), a.end(), v[i][j + 1]) - lower_bound(a.begin(), a.end(), v[i][j]);
			o = o * powmod(j + 1, cnt) % INF;
		}
		ans += o;
	}
	ans %= INF;
	if (ans < 0) ans += INF;
	cout << ans << endl;
	return 0;
}