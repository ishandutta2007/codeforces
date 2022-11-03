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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[200];
int vis[200];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		int n = str.length();
		flag[n] = 0;
		int mask = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			flag[i] = 1 << (str[i] - 'a') | flag[i + 1];
		}
		mask = flag[0];
		string key = str;
		sort(key.rbegin(), key.rend());
		key.resize(unique(key.begin(), key.end()) - key.begin());
		MEM(vis, 0);
		for (auto& c : key)
		{
			v[c].clear();
		}
		for (int i = 0; i < str.length(); i++)
		{
			v[str[i]].push_back(i);
		}
		string ans;
		int cur = -1;
		while (mask)
		{
			for (auto& c : key)
			{
				if (vis[c]) continue;
				int pos = *lower_bound(v[c].begin(), v[c].end(), cur);
				if ((flag[pos] & mask) == mask)
				{
					cur = pos;
					ans.push_back(c);
					vis[c] = 1;
					mask ^= 1 << (c - 'a');
					break;
				}
			}

		}
		puts(ans.c_str());
	}
	return 0;
}