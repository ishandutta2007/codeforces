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
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	pair<int, int> ans = { INF,INF };
	for (int i = 1; i <= 100; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += min({ abs(a[j] - i), abs(a[j] - i - 1),abs(a[j] - i + 1) });
		}
		ans = min(ans, { sum,i });
	}
	cout << ans.second << ' ' << ans.first << endl;
	return 0;
}