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
const int N = 3e5 + 10;
int flag[N];
vector<int> v;
char ans[N];
int cnt[N];
void init(int n)
{
	MEM(flag, 0);
	for (int i = 2; i <= n; i++)
	{
		if (flag[i])
		{
			v.push_back(i);
			continue;
		}
		for (int j = i + i; j <= n; j += i) flag[j] = 1;
		if (flag[i * 2]) v.push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	init(n);
	for (auto &c : str) cnt[c]++;
	int ok = 0;
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (cnt[i] >= v.size())
		{
			ok = 1;
			cnt[i] -= v.size();
			for (auto &x : v) ans[x] = i;
		}
	}
	if (!ok)
	{
		puts("NO");
		return 0;
	}
	int ptr = 'a';
	for (int i = 1; i <= n; i++)
	{
		if (ans[i]) continue;
		while (cnt[ptr] == 0) ptr++;
		ans[i] = ptr;
		cnt[ptr]--;
	}
	puts("YES");
	puts(ans + 1);
	return 0;
}