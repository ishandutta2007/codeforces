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
const int N = 1e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	map<LL, int> m;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		LL x;
		cin >> x;
		m[x]++;
	}
	if (k == 1)
	{
		cout << m.size() << endl;
	}
	else
	{
		int ans = 0;
		for (auto &p : m)
		{
			LL a = 0;
			LL b = 0;
			LL c = 0;
			LL t = p.first;
			for (int i = 0; ; i++)
			{
				int cnt = 0;
				if (m.count(t)) cnt = m[t], m[t] = 0;
				cnt += max(a, b);
				a = b;
				b = c;
				c = cnt;
				t *= k;
				if (t >= INF) break;
			}
			ans += max(b, c);
		}
		cout << ans << endl;
	}
	return 0;
}