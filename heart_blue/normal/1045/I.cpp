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
const int N = 2e5 + 10;
int a[N];
map<int, int> mc;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		int o = 0;
		for (auto& c : str)
			o ^= 1 << (c - 'a');
		a[i] = o;
		mc[a[i]]++;
	}
	int mask = 1 << 26;
	mask--;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (mc.count(a[i]))
			ans += mc[a[i]];
		for (int o = 0; o < 26; o++)
		{
			int x = a[i] ^ (1 << o);
			if (mc.count(x))
				ans += mc[x];
		}
	}
	cout << (ans - n) / 2 << endl;
	return 0;
}