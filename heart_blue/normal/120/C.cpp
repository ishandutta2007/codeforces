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
const int N = 2e5 + 50;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	while (n--)
	{
		int x;
		cin >> x;
		for (int i = 3; i > 0; i--)
		{
			if (x >= i*k)
			{
				x -= i*k;
				break;
			}
		}
		ans += x;
	}
	cout << ans << endl;
	return 0;
}