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
const int N = 2e3 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	MEM(ans, 0x3f);
	cin >> n;
	for (int o = 0; o < 2; o++)
	{
		for (int s = 0; s < 10; s++)
		{
			vector<int> v;
			for (int i = 1; i <= n; i++)
			{
				if ((i >> s & 1) == o)
				{
					v.push_back(i);
				}
			}
			if (v.empty()) continue;
			cout << v.size() << '\n';
			for (auto &x : v) cout << x << ' ';
			cout << endl;
			for (int i = 1; i <= n; i++)
			{
				int x;
				cin >> x;
				if ((i >> s & 1) == o) continue;
				ans[i] = min(ans[i], x);
			}
		}
	}
	cout << -1 << '\n';
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}