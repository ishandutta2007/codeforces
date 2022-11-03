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
const int N = 5e3 + 10;
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	sum[0] = 0;
	int a;
	cin >> a;
	string str;
	cin >> str;
	int n = str.length();
	for (int i = 1; i <= str.length(); i++)
	{
		sum[i] = str[i - 1] - '0' + sum[i - 1];
	}
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			mc[sum[i] - sum[j]]++;
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int o = sum[i] - sum[j];
			if (o == 0 && a == 0) ans += LL(n)*(n + 1) / 2;
			if (o != 0 && a % o == 0)
			{
				ans += mc[a / o];
			}
		}
	}
	cout << ans << endl;
	return 0;
}