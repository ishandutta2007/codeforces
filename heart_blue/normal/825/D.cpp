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
int a[N];
int b[N];
void refrain(string &s, int a[])
{
	for (auto &c : s) a[c]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	refrain(s1, a);
	refrain(s2, b);
	int l = 0, r = n;
	int key = 0;
	while (l <= r)
	{
		LL mid = (l + r) >> 1;
		LL need = 0;
		for (int i = 'a'; i <= 'z'; i++)
		{
			need += max(0LL, b[i] * mid - a[i]);
		}
		if (need <= a['?']) key = mid, l = mid + 1;
		else r = mid - 1;
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		a[i] = max(0, b[i] * key - a[i]);
		a['?'] -= a[i];
	}
	a['a'] += a['?'];
	int ptr = 'a';
	for (auto &c : s1)
	{
		if (c != '?') continue;
		while (a[ptr] == 0) ptr++;
		a[ptr]--;
		c = ptr;
	}
	cout << s1 << endl;
	return 0;
}