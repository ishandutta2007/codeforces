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
vector<int> v1[200], v2[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++)
	{
		v1[s1[i]].push_back(i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		v2[s2[i]].push_back(i + 1);
	}
	vector<pair<int, int>> vp;
	for (int i = 'a'; i <= 'z'; i++)
	{
		while (!v1[i].empty() && !v2[i].empty())
		{
			vp.emplace_back(v1[i].back(), v2[i].back());
			v1[i].pop_back();
			v2[i].pop_back();
		}
		while (!v1[i].empty() && !v2['?'].empty())
		{
			vp.emplace_back(v1[i].back(), v2['?'].back());
			v1[i].pop_back();
			v2['?'].pop_back();
		}
		while (!v2[i].empty() && !v1['?'].empty())
		{
			vp.emplace_back(v1['?'].back(), v2[i].back());
			v2[i].pop_back();
			v1['?'].pop_back();
		}
	}
	while (!v1['?'].empty() && !v2['?'].empty())
	{
		vp.emplace_back(v1['?'].back(), v2['?'].back());
		v1['?'].pop_back();
		v2['?'].pop_back();
	}
	printf("%d\n", vp.size());
	for (auto &p : vp)
	{
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}