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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N][3];
vector<string> vs;
vector<string> vsx = {
"If you want to call a taxi, you should call:",
"If you want to order a pizza, you should call:",
"If you want to go to a cafe with a wonderful girl, you should call:" };
int check(string &str)
{
	map<char, int> mc;
	int flag = 1;
	int pre = '0' + 10;
	for (auto &c : str)
	{
		mc[c] = 1;
		if (isdigit(c))
		{
			if (pre <= c) flag = 0;
			pre = c;
		}
	}
	if (mc.size() == 2) return 0;
	if (flag == 1) return 1;
	else return 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	int n;
	cin >> n;
	int maxv[3] = { 0,0,0 };
	for (int i = 0; i < n; i++)
	{
		int m;
		string str;
		cin >> m >> str;
		vs.push_back(str);
		while (m--)
		{
			cin >> str;
			a[i][check(str)]++;
		}
		for (int j = 0; j < 3; j++) maxv[j] = max(maxv[j], a[i][j]);
	}
	vector<string> ans[3];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == maxv[j]) ans[j].push_back(vs[i]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%s", vsx[i].c_str());
		for (int j = 0; j < ans[i].size(); j++)
		{
			printf(" %s%c", ans[i][j].c_str(), ",."[j == ans[i].size() - 1]);
		}
		puts("");
	}
	return 0;
}