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
	vector<pair<LL, LL>> vp;
	int n;
	LL x1, x2;
	cin >> n;
	cin >> x1 >> x2;
	while (n--)
	{
		int k, b;
		cin >> k >> b;
		vp.push_back({ k*x1 + b,k*x2 + b });
	}
	sort(vp.begin(), vp.end());
	LL o = -INF*INF;
	for (auto &p : vp)
	{
		if (p.second >= o) o = p.second;
		else
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}