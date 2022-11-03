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
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set<int> s0, s1;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0') s0.insert(i + 1);
		else s1.insert(i + 1);
	}
	int k = 0;
	while (!s1.empty())
	{
		if (s0.empty())
		{
			puts("-1");
			return 0;
		}
		if (*s0.begin() > *s1.begin() || *s0.rbegin() < *s1.rbegin())
		{
			puts("-1");
			return 0;
		}
		vector<int> &vp = v[k++];
		int cur = *s0.begin();
		s0.erase(cur);
		vp.push_back(cur);
		while (1)
		{
			auto iter = s1.lower_bound(cur);
			if (iter == s1.end()) break;
			int x = *iter;
			vp.push_back(x);
			s1.erase(x);
			iter = s0.lower_bound(x);
			cur = *iter;
			s0.erase(*iter);
			vp.push_back(cur);
		}
	}
	while (!s0.empty())
	{
		v[k++].push_back(*s0.begin());
		s0.erase(s0.begin());
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d", v[i].size());
		for (auto &x : v[i]) printf(" %d", x);
		puts("");
	}
	return 0;
}