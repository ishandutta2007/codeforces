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
const int N = 2e5 + 10;
vector<pair<int, int>> ans;
void solve(vector<int>& v)
{
	for (int i = 0; i + 1 < v.size(); i += 2)
	{
		ans.emplace_back(v[i], v[i + 1]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v1, v2;
	string s1, s2;
	int n;
	cin >> n;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[i]) continue;
		if (s1[i] == 'a') v1.push_back(i + 1);
		else v2.push_back(i + 1);
	}
	if ((v1.size() + v2.size()) & 1) puts("-1"), exit(0);
	solve(v1);
	solve(v2);
	if (v1.size() & 1)
	{
		ans.emplace_back(v1.back(), v1.back());
		ans.emplace_back(v1.back(), v2.back());
	}
	cout << ans.size() << '\n';
	for (auto& p : ans)
	{
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}