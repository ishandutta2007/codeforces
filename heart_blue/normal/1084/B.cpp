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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL s;
	cin >> n >> s;
	int l = 0, r = INF;
	int ret = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		r = min(r, a[i]);
	}
	while (l <= r)
	{
		int mid = (l + r) / 2;
		LL tot = 0;
		for (int i = 1; i <= n; i++)
		{
			tot += a[i] - mid;
		}
		if (tot >= s) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ret << endl;
	return 0;
}