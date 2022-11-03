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
const int N = 3e5 + 10;
int a[N];
int cnt[N * 100];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	while (cin >> n >> m)
	{
		if (n > m) swap(n, m);
		if (n == 1)
		{
			int cnt[] = { 0,0,0,0,2,4,6 };
			cout << m / 6 * 6 + cnt[m % 6] << endl;
		}
		else if (n == 2)
		{
			int ans[] = { 0,0,0,4,8,10,12,12 };
			if (m <= 3 || m == 7) cout << ans[m] << endl;
			else cout << m * 2 << endl;
		}
		else
		{
			LL ans = 1LL * n*m;
			cout << ans / 2 * 2 << endl;
		}
	}
	return 0;
}