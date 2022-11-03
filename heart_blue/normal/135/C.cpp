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
int check(string str, int pos, int o)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '?')
		{
			if (i < pos) str[i] = o + '0';
			else str[i] = (o ^ 1) + '0';
		}
	}
	int cnt[2];
	cnt[0] = count(str.begin(), str.end(), '0');
	cnt[1] = count(str.begin(), str.end(), '1');
	int ptr[2] = { 0,0 };
	int k = 1;
	while (cnt[0] > 0 && cnt[1] > 0 && cnt[0] + cnt[1] > 2)
	{
		while (ptr[k] < str.length() && str[ptr[k]] != (k + '0')) ptr[k]++;
		ptr[k]++;
		cnt[k]--;
		k ^= 1;
	}
	if (cnt[0] == 0) return 3;
	if (cnt[1] == 0) return 0;
	while (ptr[0] < str.length() && str[ptr[0]] != '0') ptr[0]++;
	while (ptr[1] < str.length() && str[ptr[1]] != '1') ptr[1]++;
	if (ptr[0] < ptr[1]) return 1;
	else return 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	vector<int> v;
	cin >> str;
	for (int o = 0; o < 2; o++)
	{
		int cur = 0;
		while (cur <= str.length())
		{
			int key = check(str, cur, o);
			v.push_back(key);
			int l = cur;
			int r = str.length();
			int res = l;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (check(str, mid, o) == key) res = mid, l = mid + 1;
				else r = mid - 1;
			}
			cur = res + 1;
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto& x : v)
	{
		if (x == 0) puts("00");
		if (x == 1) puts("01");
		if (x == 2) puts("10");
		if (x == 3) puts("11");
	}
	return 0;
}