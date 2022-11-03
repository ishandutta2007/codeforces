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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int o = 0; n >> o; o++)
		{
			vector<int> v[2];
			for (int i = 1; i <= n; i++)
			{
				v[i >> o & 1].push_back(i);
			}
			cout << v[0].size() << ' ' << v[1].size();
			for (int i = 0; i < 2; i++)
			{
				for (auto& x : v[i])
					cout << ' ' << x;
			}
			cout << endl;
			int res;
			cin >> res;
			ans = max(ans, res);
		}
		cout << "-1 " << ans << endl;
	}
	return 0;
}