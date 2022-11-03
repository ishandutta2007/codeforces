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
const int N = 5e3 + 10;
int sum1[N];
int sum2[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum1[i] = sum1[i - 1];
		sum2[i] = sum2[i - 1];
		cin >> a[i];
		if (a[i] == 1) sum1[i]++;
		else sum2[i]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int o1 = 0, o2 = 0;
		for (int j = i; j > 0; j--)
		{
			if (a[j] == 2) o2 = max(o2 + 1, o1 + 1);
			if (a[j] == 1) o1++;
			int o = o2 = max(o2, o1);
			ans = max(ans, o + sum2[n] - sum2[i] + sum1[j - 1]);
			if (ans == 10)
				ans = 10;
		}
	}
	cout << ans << endl;
	return 0;
}