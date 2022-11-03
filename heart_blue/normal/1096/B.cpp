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
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n;
	cin >> str;
	const int MOD = 998244353;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == str[0]) cnt1++;
		else break;
	}
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == str.back()) cnt2++;
		else break;
	}
	if (cnt1 == n)
	{
		cout << 1LL * n*(n + 1) / 2 % MOD << endl;
	}
	else
	{
		if (str.front() == str.back()) cout << 1LL * (cnt1 + 1)*(cnt2 + 1) % MOD << endl;
		else cout << cnt1 + cnt2 + 1 << endl;
	}
	return 0;
}