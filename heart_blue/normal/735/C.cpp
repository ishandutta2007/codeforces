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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL f[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	f[0] = f[1] = 1;
	for (int i = 2; ; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] > INF*INF) break;
	}
	LL ans;
	cin >> ans;
	for (int i = 1; ; i++)
	{
		if (ans < f[i])
		{
			ans = i;
			break;
		}
	}
	cout << ans - 2 << endl;
	return 0;
}