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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<LL, LL>> ans;
	LL n;
	cin >> n;
	LL x = 0;
	for (LL i = 1; i <= n; i++)
	{
		x += i*i;
		if (x > n) break;
		LL s = i*(i + 1) / 2;
		if ((n - x) % s == 0)
		{
			ans.push_back({ i,(n - x) / s + i });
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		if (ans[i].first != ans[i].second)
		{
			ans.push_back({ ans[i].second,ans[i].first });
		}
	}
	cout << ans.size() << endl;
	for (auto &p : ans)
	{
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}