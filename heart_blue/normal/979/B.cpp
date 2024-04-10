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
const int N = 2e2 + 10;
int cnt[N];
int check(string &str, int k)
{
	MEM(cnt, 0);
	int maxv = 0;
	for (auto &c : str)
	{
		maxv = max(maxv, ++cnt[c]);
	}
	if (maxv == str.length() && k == 1) return maxv - 1;
	return min(maxv + k, int(str.length()));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs = { "Kuro","Shiro","Katie" };
	vector<pair<int, int>> vp;
	int k;
	cin >> k;
	for (int i = 0; i < 3; i++)
	{
		string str;
		cin >> str;
		vp.push_back({ check(str,k),i });
	}
	sort(vp.begin(), vp.end());
	if (vp[1].first == vp[2].first) puts("Draw");
	else puts(vs[vp[2].second].c_str());
	return 0;
}