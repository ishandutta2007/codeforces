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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	int maxv = b;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (b > 0) b--;
			else if (a > 0) a--;
			else break;
		}
		else
		{
			if (b == maxv)
			{
				b--;
			}
			else if (a > 0) a--, b++;
			else if (b > 0) b--;
			else break;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}