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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, string>> vs(n);
	for (auto &p : vs)
	{
		cin >> p.second >> p.first;
	}
	vector<string> ans;
	sort(vs.begin(), vs.end());
	for (auto &p : vs)
	{
		if (ans.size() < p.first)
		{
			puts("-1");
			return 0;
		}
		ans.insert(ans.end() - p.first, p.second);
	}
	map<string, int> ms;
	for (int i = 0; i < ans.size(); i++) ms[ans[i]] = i + 1;
	for (auto &p : vs)
	{
		printf("%s %d\n", p.second.c_str(), ms[p.second]);
	}
	return 0;
}