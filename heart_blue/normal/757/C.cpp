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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
vector<int> v[M];
int a[M];
LL fact[M];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < M; i++)
	{
		fact[i] = i * fact[i - 1] % INF;
	}
}
LL powmod(int a, int b, int mod = INF)
{
	LL ret = 1;
	while (b--)
	{
		ret = ret * a % mod;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	init();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int o;
		cin >> o;
		while (o--)
		{
			int x;
			cin >> x;
			v[x].push_back(i);
		}
	}
	sort(v + 1, v + m + 1);
	int cnt = 1;
	LL ans = 1;
	for (int i = 2; i <= m; i++)
	{
		if (v[i] == v[i - 1]) cnt++;
		else
		{
			ans = ans * fact[cnt] % INF;
			cnt = 1;
		}
	}
	ans = ans * fact[cnt] % INF;
	cout << ans << endl;

	return 0;
}