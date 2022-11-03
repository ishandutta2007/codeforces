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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n;i++) cin >> a[i];
	int ans = -1;
	int sum = 0;
	while (1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == -1) continue;
			if (sum >= a[i])
			{
				a[i] = -1;
				sum++;
			}
		}
		ans++;
		if (sum == n) break;
		for (int i = n; i >= 1; i--)
		{
			if (a[i] == -1) continue;
			if (sum >= a[i])
			{
				a[i] = -1;
				sum++;
			}
		}
		ans++;
		if (sum == n) break;
	}
	cout << ans << endl;
	return 0;
}