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
#include <random>
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
	LL n, b;
	cin >> n >> b;
	LL ans = INF * INF;
	vector<pair<LL, int>> v;
	for (int i = 2; 1LL * i * i <= b; i++)
	{
		if (b % i) continue;
		int cnt = 0;
		while (b % i == 0) cnt++, b /= i;
		v.emplace_back(i, cnt);
	}
	if (b > 1) v.emplace_back(b, 1);
	for (auto& p : v)
	{
		LL x, cnt;
		tie(x, cnt) = p;
		LL m = n;
		LL tot = 0;
		while (m)
		{
			tot += m / x;
			m /= x;
		}
		ans = min(ans, tot / cnt);
	}
	cout << ans << endl;
	return 0;
}