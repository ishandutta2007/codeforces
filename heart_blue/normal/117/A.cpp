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

const int INF = 1e9 + 7;
const int N = 2e5 + 1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int r = (m - 1) * 2;
	while (n--)
	{
		int s, f, t;
		cin >> s >> f >> t;
		if (s == f)
		{
			cout << t << endl;
			continue;
		}
		int x = t%r + 1;
		if (x <= m - 1)
		{
			if (x <= s)
			{
				int ans = s - x;
				if (f >= s) ans += f - s;
				else ans += m * 2 - f - s;
				cout << ans + t << endl;
			}
			else
			{
				int ans = 2 * m - s - x;
				if (f <= s) ans += s - f;
				else ans += s + f - 2;
				cout << ans + t << endl;
			}
		}
		else
		{
			x = r - x+2;
			if (x >= s)
			{
				int ans = x - s;
				if (f <= s) ans += s - f;
				else ans += s + f - 2;
				cout << ans + t << endl;
			}
			else
			{
				int ans = s + x - 2;
				if (f >= s) ans += f - s;
				else ans += 2 * m - s - f;
				cout << ans + t << endl;
			}
		}
	}
	
	return 0;
}