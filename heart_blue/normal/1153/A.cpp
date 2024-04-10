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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t;
	cin >> n >> t;
	pair<int, int> ans = { (int)INF,0 };
	for (int i = 1; i <= n; i++)
	{
		int s, d;
		cin >> s >> d;
		if (s > t) ans = min(ans, { s,i });
		else ans = min(ans, { s + (t - s + d - 1) / d * d,i });
	}
	cout << ans.second << endl;
	return 0;
}