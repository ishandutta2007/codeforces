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
void check(vector<string>& vs, string& str, int x, int y, int dx, int dy)
{
	for (int i = 0; i < str.length(); i++)
	{
		vs[x][y] = str[i];
		x += dx;
		y += dy;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs(6);
	vector<string> ans(66, string(66, 'z'));
	for (auto& s : vs) cin >> s;
	sort(vs.begin(), vs.end());
	do
	{
		auto& row1 = vs[0];
		auto& row2 = vs[1];
		auto& row3 = vs[2];
		auto& col1 = vs[3];
		auto& col2 = vs[4];
		auto& col3 = vs[5];
		if (row1.front() != col1.front()) continue;
		if (row1.back() != col2.front()) continue;
		if (row2.front() != col1.back()) continue;
		if (row2.back() != col3.front()) continue;
		if (row3.front() != col2.back()) continue;
		if (row3.back() != col3.back()) continue;
		if (row1.length() + row3.length() - 1 != row2.length()) continue;
		if (col1.length() + col3.length() - 1 != col2.length()) continue;
		if (row2[row1.length() - 1] != col2[col1.length() - 1]) continue;
		int n = col2.length();
		int m = row2.length();
		vector<string> tmp(n, string(m, '.'));
		check(tmp, row1, 0, 0, 0, 1);
		check(tmp, row2, col1.length() - 1, 0, 0, 1);
		check(tmp, row3, n - 1, row1.length() - 1, 0, 1);

		check(tmp, col1, 0, 0, 1, 0);
		check(tmp, col2, 0, row1.length() - 1, 1, 0);
		check(tmp, col3, col1.length() - 1, m - 1, 1, 0);
		if (ans > tmp)
			ans = tmp;
	} while (next_permutation(vs.begin(), vs.end()));
	if (ans[0][0] == 'z') puts("Impossible");
	else for (auto& s : ans) puts(s.c_str());
	return 0;
}