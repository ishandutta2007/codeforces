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
LL powmod(LL a, LL b, LL mod = INF)
{
	LL ret = 1;
	LL o = a;
	while (b)
	{
		if (b & 1) ret = ret*o%mod;
		b >>= 1;
		o = o*o%mod;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int len = str.length();
	int k;
	cin >> k;
	LL q = powmod(2, len);
	LL tot = (powmod(q, k) - 1)*powmod(q - 1, INF - 2) % INF;
	if (tot < 0) tot += INF;
	LL ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '0' || str[i] == '5')
		{
			ans += tot*powmod(2, i) % INF;
			if (ans >= INF) ans -= INF;
		}
	}
	cout << ans << endl;

	return 0;
}