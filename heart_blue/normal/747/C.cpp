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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	MEM(a, -1);
	cin >> n >> q;
	while (q--)
	{
		int t, k, d;
		cin >> t >> k >> d;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] < t) cnt++;
		}
		if (cnt < k)
		{
			cout << -1 << '\n';
		}
		else
		{
			int sum = 0;
			for (int i = 1; i <= n && k > 0; i++)
			{
				if (a[i] < t)
				{
					a[i] = t + d - 1;
					k--;
					sum += i;
				}
			}
			cout << sum << '\n';
		}
	}


	return 0;
}