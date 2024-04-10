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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b, n;
	cin >> n >> a >> b;
	n *= 6;
	LL ans = INF*INF;
	LL ka = a, kb = b;
	for (LL i = a; i < N; i++)
	{
		LL o = (n - 1) / i + 1;
		o = max(o, b);
		if (ans > o * i)
		{
			ka = i, kb = o;
			ans = ka*kb;
		}
	}
	for (LL i = b; i < N; i++)
	{
		LL o = (n - 1) / i + 1;
		o = max(o, a);
		if (ans > o * i)
		{
			ka = o, kb = i;
			ans = ka*kb;
		}
	}
	cout << ka * kb << endl;
	cout << ka << ' ' << kb << endl;

	return 0;
}