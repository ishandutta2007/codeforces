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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL h, n;
	cin >> h >> n;
	h = 1LL << h;
	LL ans = 0;
	int o = 1;
	while (h > 1)
	{
		if (o == 1)
		{
			if (n > h / 2) ans += h;
			else o = -o, ans++;
		}
		else
		{
			if (n <= h / 2) ans += h;
			else o = -o, ans++;
		}
		h /= 2;
		if (n > h) n -= h;
	}
	cout << ans<< endl;
	return 0;
}