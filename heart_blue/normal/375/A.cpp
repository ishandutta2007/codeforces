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
const int N = 2e5 + 10;
int a[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	a[1] = a[6] = a[8] = a[9] = -1;
	string str;
	cin >> str;
	for (auto &c : str) a[c - '0']++;
	vector<int> v = { 1,6,8,9 };
	int o = 0;
	for (int i = 9; i > 0; i--)
	{
		while (a[i]--)
		{
			o = (o * 10 + i) % 7;
			putchar(i + '0');
		}
	}
	o = (o * 10000) % 7;
	do
	{
		int r = 0;
		for (auto &x : v) r = (r * 10 + x) % 7;
		if ((r + o) % 7 == 0) break;
	} while (next_permutation(v.begin(), v.end()));
	for (auto &x : v) putchar(x + '0');
	while (a[0]--) putchar('0');
	return 0;
}