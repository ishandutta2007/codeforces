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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int flag[N];
int check(int n)
{
	MEM(flag, 0);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; i + j + k <= n; k++)
			{
				flag[i + j * 5 + k * 10 + (n - i - j - k) * 50] = 1;
			}
		}
	}
	int tot = 0;
	for (int i = 0; i < N; i++) tot += flag[i];
	return tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n <= 500)
	{
		printf("%d\n", check(n));
		return 0;
	}
	printf("%lld\n", 49LL * n - 247);
	return 0;
}