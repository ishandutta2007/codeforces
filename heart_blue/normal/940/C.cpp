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
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	string str, s;
	cin >> str;
	map<int, int> mc;
	for (auto &c : str) mc[c] = 1;
	int o = 0;
	for (auto &p : mc) p.second = o++, s += p.first;
	if (str.length() < k)
	{
		cout << str << string(k - str.length(), s[0]) << endl;
		return 0;
	}
	MEM(a, 0);
	for (int i = 0; i < k; i++) a[i] = mc[str[i]];
	a[k - 1]++;
	for (int i = k - 1; i >= 0; i--)
	{
		if (a[i] >= mc.size()) a[i] = 0, a[i - 1]++;
	}
	for (int i = 0; i < k; i++) putchar(s[a[i]]);
	return 0;
}