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
vector<int> v[N];
int check(vector<int> &v1, vector<int> &v2)
{
	int ptr = 0;
	int ret = 0;
	int o = -1;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] < o) continue;
		ret++;
		while (ptr < v2.size() && v2[ptr] < v1[i]) ptr++;
		if (ptr == v2.size()) break;
		ret++;
		o = v2[ptr];
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	map<int, int> mc;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
		mc[x] = 1;
	}
	int ans = 0;
	for (auto &p1 : mc)
	{
		ans = max(ans, (int)v[p1.first].size());
		for (auto &p2 : mc)
		{
			if (p1.first == p2.first) continue;
			ans = max(ans, check(v[p1.first], v[p2.first]));
		}
	}
	cout << ans << endl;
	return 0;
}