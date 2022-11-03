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
const int N = 2e2 + 10;
vector<int> v[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int x;
	int ans = 0;
	while (n--)
	{
		cin >> x;
		v[x % 10].push_back(x);
		ans += x / 10;
	}
	for (int i = 9; i > 0; i--)
	{
		int o = 10 - i;
		for (auto &x : v[i])
		{
			if (k >= o)
			{
				k -= o;
				v[0].push_back(x + o);
				ans++;
			}
			else break;
		}
	}
	k /= 10;
	for (auto &x : v[0])
	{
		x /= 10;
		int o = min(k, 10 - x);
		ans += o;
		k -= o;
	}
	cout << ans << endl;
	return 0;
}