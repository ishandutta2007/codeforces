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
const int N = 2e2 + 10;
vector<int> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m;
	cin >> m;
	string str;
	cin >> str;
	char key = 'z';
	int n = str.length();
	for (int i = 0; i < n; i++)
	{
		vp[str[i]].push_back(i);
	}
	for (int c = 'a'; c <= 'z'; c++)
	{
		int pre = -1;
		if (vp[c].empty()) continue;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] > c) continue;
			if (i - pre - 1 >= m) break;
			pre = i;
		}
		if (n - pre - 1 < m)
		{
			key = c;
			break;
		}
	}
	vector<int> v;
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] < key)
		{
			v.push_back(i);
		}
	}
	v.push_back(n);
	int ptr = 0;
	int cnt = 0;
	int pre = min(n - 1, m - 1);
	for (int i = 0; i < v.size(); i++)
	{
		while (1)
		{
			if (pre >= v[i])
			{
				pre = max(pre, v[i] + m);
				break;
			}
			while (ptr + 1 < vp[key].size() && vp[key][ptr + 1] <= pre) ptr++;
			cnt++;
			pre = vp[key][ptr] + m;
		}
	}
	for (int i = 'a'; i < key; i++) cout << string(vp[i].size(), i);
	cout << string(cnt, key);
	return 0;
}