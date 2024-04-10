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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		sum1 += a[i];
		sum2 += b[i];
	}
	int ans = abs(sum1 -sum2);
	int key = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += b[i] - a[i];
		sum2 += a[i] - b[i];
		int o = abs(sum1 - sum2);
		if (o > ans)
		{
			ans = o;
			key = i + 1;
		}
		sum1 -= b[i] - a[i];
		sum2 -= a[i] - b[i];
	}
	cout << key << endl;
	return 0;
}