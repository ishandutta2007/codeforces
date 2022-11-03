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
const int N = 1e5 + 10;
LL L[N];
LL R[N];
pair<int, int> p[N];
LL powmod(LL a, LL b, LL mod = INF)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret*a%mod;
		b >>= 1;
		a = a*a%mod;
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mc[x]++;
	}
	int k = 0;
	for (auto &pp : mc)
	{
		p[++k] = pp;
	}
	L[0] = R[k + 1] = 1;
	for (int i = 1; i <= k; i++)
	{
		L[i] = (p[i].second + 1)*L[i - 1] % (INF - 1);
	}
	for (int i = k; i >= 1; i--)
	{
		R[i] = (p[i].second + 1)*R[i + 1] % (INF - 1);
	}
	LL ans = 1;
	for (int i = 1; i <= k; i++)
	{
		LL o = 1;
		while (p[i].second--)
		{
			o = o*p[i].first%INF;
			ans *= powmod(o, L[i - 1] * R[i + 1] % (INF - 1));
			ans %= INF;
		}
	}
	cout << ans << endl;
	return 0;
}