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
const int N = 1e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<pair<int, string>, vector<int>> mc;
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int o = 0;
		for (auto& c : s2)
		{
			o |= 1 << (c - 'a');
		}
		while (!s1.empty())
		{
			int x = s1.back() - 'a';
			if (o >> x & 1) s1.pop_back();
			else break;
		}
		mc[{o, s1}].push_back(i);
	}
	printf("%d\n", mc.size());
	for (auto& p : mc)
	{
		auto& v = p.second;
		printf("%d", v.size());
		for (auto& x : v)
			printf(" %d", x);
		puts("");
	}
	return 0;
}