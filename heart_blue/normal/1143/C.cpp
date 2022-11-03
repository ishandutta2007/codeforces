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
const int N = 1e5 + 10;
int cnt[N];
vector<int> v[N];
int flag[N];
int fa[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int p;
		cin >> p >> flag[i];
		p = max(0, p);
		v[p].push_back(flag[i]);
		fa[i] = p;
		cnt[p] += flag[i];
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() == cnt[i] && flag[i])
			ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) ans.push_back(-1);
	for (auto& x : ans) cout << x << ' ';
	return 0;
}