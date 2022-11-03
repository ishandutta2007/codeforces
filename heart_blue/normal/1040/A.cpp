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
const int N = 5e3 + 10;
int v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) cin >> v[i];
	int l = 1, r = n;
	int ans = 0;
	while (l <= r)
	{
		if (v[l] != 2 && v[r] != 2)
		{
			if (v[l] != v[r])
			{
				cout << -1 << endl;
				return 0;
			}
		}
		else if (v[l] + v[r] == 2)
		{
			ans += a;
		}
		else if (v[l] + v[r] == 3)
		{
			ans += b;
		}
		else
		{
			ans += (1 + (l != r)) * min(a, b);
		}
		l++, r--;
	}
	cout << ans << endl;
	return 0;
}