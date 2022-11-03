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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<LL, LL> m;
	while (n--)
	{
		int x;
		cin >> x;
		m[x]++;
	}
	LL ans = 0;
	for (auto &p : m)
	{
		LL t = 1LL << 40;
		LL x;
		LL c;
		tie(x, c) = p;
		while (t > x)
		{
			if (t - x == x) ans += c*(c-1);
			else if (m.count(t - x)) ans += c*m[t - x];
			t >>= 1;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}