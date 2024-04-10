#pragma comment(linker, "/STACK:102400000,102400000") 
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
vector<int> v;
int ans[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++)
	{
		ans[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		if (a[x] > a[y])
		{
			ans[x]--;
		}
		else if (a[x] < a[y])
		{
			ans[y]--;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}