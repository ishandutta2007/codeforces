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
	cin >> n;
	map<LL, int> mc;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mc[a[i]]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int flag = 1;
		for (int j = 0; j < 40; j++)
		{
			LL x = (1LL << j) - a[i];
			if (x == a[i])
			{
				if (mc[x] > 1)
				{
					flag = 0;
					break;
				}
				continue;
			}
			if (mc.count(x))
			{
				flag = 0;
				break;
			}
		}
		ans += flag;
	}
	cout << ans << endl;
	return 0;
}