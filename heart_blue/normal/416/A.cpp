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
const LL INF = 1e9+1;
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	int t;
	char c;
	int l = -INF;
	int r = INF;
	while (n--)
	{
		cin >> str >> t >> c;
		if (str == ">=")
		{
			if (c == 'Y') l = max(l, t);
			else r = min(r, t - 1);
		}
		if (str == ">")
		{
			if (c == 'Y') l = max(l, t+1);
			else r = min(r, t);
		}
		if (str == "<=")
		{
			if (c == 'Y') r = min(r, t);
			else l = max(l, t + 1);
		}
		if (str == "<")
		{
			if (c == 'Y') r = min(r, t - 1);
			else l = max(l, t);
		}
	}
	if (l > r) cout << "Impossible" << endl;
	else cout << l << endl;

	return 0;
}