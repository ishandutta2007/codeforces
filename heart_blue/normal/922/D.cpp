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
LL check(string &str)
{
	LL ret = 0;
	LL s = 0;
	for (auto &c : str)
	{
		if (c == 's') s++;
		else ret += s;
	}
	return ret;
}
pair<LL, LL> getsum(string &str)
{
	LL s = 0, h = 0;
	for (auto &c : str)
	{
		if (c == 's') s++;
		else h++;
	}
	return { s,h };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<LL, LL>> vp;
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		ans += check(str);
		vp.push_back(getsum(str));
	}
	sort(vp.begin(), vp.end(), [](pair<LL, LL> &p1, pair<LL, LL> &p2) -> bool
	{
		LL a, b, c, d;
		tie(a, b) = p1;
		tie(c, d) = p2;
		return a * d > b * c;
	});
	string str;
	for (auto &p : vp)
	{
		str += string(p.second, 'h');
		str += string(p.first, 's');
	}
	ans += check(str);
	cout << ans << endl;
	return 0;
}