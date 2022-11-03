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
const int N = 3e2 + 10;
bool check(vector<string>& vs1, vector<string>& vs2)
{
	int ptr = 0;
	for (int i = 0; i < vs1.size(); i++)
	{
		while (ptr < vs2.size() && vs2[ptr] != vs1[i]) ptr++;
		if (ptr == vs2.size()) return false;
		ptr++;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs1;
	int n;
	cin >> n;
	vs1.resize(n);
	map<string, int> ms;
	for (auto& s : vs1) cin >> s;
	for (int i = 0; i < n; i++)
	{
		ms[vs1[i]] = i;
	}
	int q;
	cin >> q;
	pair<int, int> ans = { 0,0 };
	for(int o = 1; o <= q; o++)
	{
		int sz;
		cin >> sz;
		vector<string> vs2(sz);
		for (auto& s : vs2) cin >> s;
		sort(vs1.begin(), vs1.end());
		do
		{
			int cnt = 0;
			if (!check(vs1, vs2)) continue;
			for (int i = 0; i + 1 < vs1.size(); i++)
			{
				for (int j = i + 1; j < vs1.size(); j++)
				{
					if (ms[vs1[i]] > ms[vs1[j]])
						cnt++;
				}
			}
			ans = max(ans, make_pair(n * (n - 1) / 2 - cnt + 1, -o));
		} while (next_permutation(vs1.begin(), vs1.end()));
	}
	if (ans.first == 0)
	{
		puts("Brand new problem!");
	}
	else
	{
		printf("%d\n", -ans.second);
		printf("[:%s:]\n", string(ans.first, '|').c_str());
	}
	return 0;
}