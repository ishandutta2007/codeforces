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
const int N = 2e2 + 10;
map<string, int> ms;
int flag[N];
bool check(const string &s, int k)
{
	int ret = 0;
	for (auto &c : s)
	{
		if (flag[c]) continue;
		ret++;
	}
	return ret <= k;
}
vector<string> vs;
int check(int k)
{
	int ans = 0;
	for (int i = 0; i < vs.size(); i++)
	{
		if (i > 0 && vs[i] == vs[i - 1]) continue;
		if (check(vs[i], k))
			ans++;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	string s;
	cin >> s;
	for (int i = 'a'; i <= 'z'; i++) flag[i] = s[i - 'a'] - '0';
	int k;
	cin >> k;

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		vs.clear();
		for (int j = 0; i + j <= n; j++)
		{
			vs.push_back(str.substr(j, i));
		}
		sort(vs.begin(), vs.end());
		ans += check(k);
	}
	cout << ans << endl;
	return 0;
}