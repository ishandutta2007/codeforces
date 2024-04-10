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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ans = 0;
	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > l)
		{
			ans++;
			if (a[i - 1] > l) ans--;
		}
	}
	while (m--)
	{
		int op;
		cin >> op;
		if (op == 0)
		{
			cout << ans << '\n';
		}
		else
		{
			int pos, val;
			cin >> pos >> val;
			if (a[pos] > l) continue;
			a[pos] += val;
			if (a[pos] > l)
			{
				ans++;
				if (a[pos - 1] > l) ans--;
				if (a[pos + 1] > l) ans--;
			}
		}
	}
	return 0;
}