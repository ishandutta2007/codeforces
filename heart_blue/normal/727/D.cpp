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
map<string, int> ms;
vector<string> vs;
vector<int> v[N];
int a[N];
int ans[N];
void init()
{
	ms["S"] = 1;
	ms["M"] = 2;
	ms["L"] = 3;
	ms["XL"] = 4;
	ms["XXL"] = 5;
	ms["XXXL"] = 6;
	ms["S,M"] = 7;
	ms["M,L"] = 8;
	ms["L,XL"] = 9;
	ms["XL,XXL"] = 10;
	ms["XXL,XXXL"] = 11;
	vs.resize(12);
	for (auto& p : ms)
	{
		vs[p.second] = p.first;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	for (int i = 1; i <= 6; i++)
	{
		cin >> a[i];
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		v[ms[str]].push_back(i);
	}
	for (int i = 1; i <= 6; i++)
	{
		if (v[i].size() > a[i]) puts("NO"), exit(0);
		while (a[i] && !v[i].empty())
		{
			a[i]--;
			ans[v[i].back()] = i;
			v[i].pop_back();
			if (v[i].empty()) break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		auto& v = ::v[i + 6];
		if (a[i] + a[i + 1] < v.size()) puts("NO"), exit(0);
		while (a[i] && !v.empty())
		{
			a[i]--;
			ans[v.back()] = i;
			v.pop_back();
			if (v.empty()) break;
		}
		while (a[i + 1] && !v.empty())
		{
			a[i + 1]--;
			ans[v.back()] = i + 1;
			v.pop_back();
			if (v.empty()) break;
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		puts(vs[ans[i]].c_str());
	return 0;
}