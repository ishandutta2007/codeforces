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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	fill(flag, flag + N, 1);
	flag[n - 1] = -1;
	flag[n] = -1;
	int cur = a[n] - a[n - 1];
	for (int i = n - 2; i >= 1; i--)
	{
		if (a[i] <= cur)
		{
			flag[i] = -1;
			flag[i + 1] *= -1;
		}
		else flag[i + 1] *= -1;
		cur = abs(cur - a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		flag[i] *= flag[i - 1];
		if (flag[i] == 1) putchar('+');
		else putchar('-');
	}


	return 0;
}