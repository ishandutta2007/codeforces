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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
LL a[N];
map<LL, int> mc;
void add(LL x)
{
	mc[x]++;
}
void del(LL x)
{
	mc[x]--;
	if (mc[x] == 0) mc.erase(x);
}
bool isvalid(map<char, int> &mc)
{
	if (mc.size() == 2)
	{
		if (mc.begin()->second == 2)
			return true;
	}
	if (mc.size() == 1)
		return true;
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int l = 0, r = n - 1;
	int ans = 0;
	while (l < r)
	{
		string str = { s1[l],s1[r],s2[l],s2[r] };

		int minv = INF;
		string ss = str;
		for (auto i : ss)
		{
			for (auto j : ss)
			{
				str[0] = i;
				str[1] = j;
				int sum = (s1[l] != i) + (s1[r] != j);
				map<char, int> mc;
				for (auto &c : str) mc[c]++;
				if (isvalid(mc))
					minv = min(minv, sum);
			}
		}
		ans += minv;
		l++, r--;
	}
	if (l == r && s1[l] != s2[r]) ans++;
	printf("%d\n", ans);
	return 0;
}