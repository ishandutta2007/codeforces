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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b, k;
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", &str[1]);
	int cnt = 0;
	vector<pair<int, int>> vp;
	int tot = 0;
	str[n + 1] = '1';
	for (int i = 1; i <= n + 1; i++)
	{
		if (str[i] == '1')
		{
			if (cnt) vp.push_back({ i - cnt,i }), tot += cnt / b;
			cnt = 0;
		}
		else cnt++;
	}
	vector<int> ans;
	for (auto &p : vp)
	{
		int l, r;
		tie(l, r) = p;
		for (int i = l; i + b <= r; i += b)
		{
			if (tot-- >= a)ans.push_back(i + b - 1);
		}
	}
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}