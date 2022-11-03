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
const int N = 2e3 + 10;
int flag[N];
int n;
vector<string> vs;
void solve(string &s1, string &s2)
{
	swap(s1, s2);
	if (s1.substr(1) != s2.substr(0, s2.length() - 1)) return;
	MEM(flag, 0);
	string ans;
	for (auto &s : vs)
	{
		if (flag[s.size()] != 1 && s1.substr(0, s.length()) == s)
		{
			ans.push_back('P');
			flag[s.size()] = 1;
			continue;
		}
		if (flag[s.size()] != 2 && s2.substr(s2.length() - s.length()) == s)
		{
			ans.push_back('S');
			flag[s.size()] = 2;
			continue;
		}
		return;
	}
	cout << ans << endl;
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	vs.resize(2 * n - 2);
	vector<string> v;
	for (int i = 0; i < vs.size(); i++)
	{
		cin >> vs[i];
		if (vs[i].length() == n - 1) v.push_back(vs[i]);
	}
	solve(v[0], v[1]);
	solve(v[0], v[1]);
	return 0;
}