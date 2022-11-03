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
int sum1[N];
int sum2[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 2; i <= n + 1; i++)
	{
		cin >> a[i];
		sum1[i] = a[i] + sum1[i - 2];
	}
	for (int i = n + 1; i >= 0; i--)
	{
		sum2[i] = a[i] + sum2[i + 2];
	}
	int ans = 0;
	for (int i = 2; i <= n + 1; i++)
	{
		if (sum1[i - 1] + sum2[i + 2] == sum1[i - 2] + sum2[i + 1])
			ans++;
	}
	cout << ans << endl;
	return 0;
}