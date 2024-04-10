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
const int N = 1e6 + 10;
int cnt[200];
int cnt2[200];
char str[N];
int flag[2000];
int getmax(char c = 'z')
{
	char ret = 'a';
	for (int i = c; i >= 'a'; i--)
	{
		if (cnt[i])
		{
			ret = i;
			break;
		}
	}
	cnt[ret]--;
	return ret;
}
int getmin(char c = 'a')
{
	char ret = 'a';
	for (int i = c; i <= 'z'; i++)
	{
		if (cnt[i])
		{
			ret = i;
			break;
		}
	}
	cnt[ret]--;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, len, k;
	scanf("%d%d%d", &n, &len, &k);
	scanf("%s", str + 1);
	for (int i = 1; i <= n * len; i++) cnt[str[i]]++;
	vector<string> vs(n);
	string str;
	str.reserve(len * 4);
	for (char c = 'a'; c <= 'z'; c++)
	{
		int l = 1, r = min(len - int(str.length()), cnt[c]);
		if (l > r) continue;
		int key = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			for (int i = 0; i < mid; i++) str.push_back(c);
			for (int i = 'a'; i <= 'z'; i++) cnt2[i] = cnt[i];
			for (auto& c : str) cnt2[c]--;
			int cost = k - 1;
			int ok = 1;
			char cur = 'a';
			for (auto& c : str)
			{
				while (cur < c)
				{
					int o = min(cost, cnt2[cur]);
					cnt2[cur] -= o;
					cost -= o;
					if (cost == 0) break;
					cur++;
				}
				if (cost > cnt2[c])
				{
					ok = 0;
					break;
				}
				cnt2[c] -= cost;
			}
			for (int i = 0; i < mid; i++) str.pop_back();
			if (ok) key = mid, l = mid + 1;
			else r = mid - 1;
		}
		while (key--) str.push_back(c);
	}
	k--;
	int cost = k;
	vs[k] = str;
	for (auto& c : str) cnt[c]--;
	for (int i = 0; i < len; i++)
	{
		char cur = 'a';
		while (cur < str[i])
		{
			int ptr = k - cost;
			int o = min(cost, cnt[cur]);
			cnt[cur] -= o;
			cost -= o;
			while (o--) vs[ptr++].push_back(cur);
			if (cost == 0) break;
			cur++;
		}
		int ptr = k - cost;
		cnt[str[i]] -= cost;
		for (int j = 0; j < cost; j++)
			vs[ptr + j].push_back(str[i]);
	}
	for (auto& s : vs)
	{
		while (s.length() < len)
			s.push_back(getmin());
		puts(s.c_str());
	}
	return 0;
}