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
	int n, a, b;
	cin >> n >> a >> b;
	int c = 0;
	int ans = 0;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			if (a > 0) a--;
			else if (b > 0) b--, c++;
			else if (c > 0) c--;
			else ans++;
		}
		else
		{
			if (b > 0) b--;
			else ans += 2;
		}
	}
	cout << ans << endl;
	return 0;
}