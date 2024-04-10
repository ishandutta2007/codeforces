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
const int N = 2e3 + 10;
LL sum[N];
int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
int flag[N];
int p[] = { 1,10,100,1000,10000,100000,1000000 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		flag[str[0] - 'a'] = 1;
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.length(); i++)
		{
			sum[str[i] - 'a'] += p[i];
		}
	}
	LL ans = INF * INF;
	do
	{
		LL res = 0;
		for (int i = 0; i < 10; i++)
		{
			if (a[i] == 0 && flag[i])
			{
				res = INF * INF;
				break;
			}
			res += a[i] * sum[i];
		}
		ans = min(ans, res);
	} while (next_permutation(a, a + 10));
	cout << ans << endl;
	return 0;
}