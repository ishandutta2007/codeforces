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
const int N = 2e5 + 10;
map<int, int> mc[N];
int sz[N];
LL solve(map<int, int> &ms, int n, int mod = INF)
{
	int cnt = 0;
	for (auto &p : ms)
	{
		if (p.second == 2) cnt++;
	}
	LL ans = 1;
	for (int i = 1; i <= n; i++)
	{
		int x = i;
		while (!(x & 1) && cnt > 0) x >>= 1, cnt--;
		ans = ans*x%mod;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> m;
	int k = 0;
	MEM(sz, 0);
	for (int i = 1; i <= 2*n; i++)
	{
		int x;
		cin >> x;
		if (!m.count(x)) m[x] = k++;
		int o = i;
		if (o > n) o -= n;
		x = m[x];
		mc[x][o]++;
		sz[x]++;
	}
	int mod;
	cin >> mod;
	LL ans = 1;
	for (int i = 0; i < k; i++)
	{
		ans = ans * solve(mc[i], sz[i], mod) % mod;
	}
	cout << ans << endl;
	return 0;
}