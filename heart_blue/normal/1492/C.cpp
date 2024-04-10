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
int l[N];
int r[N];
void build(string& s1, string& s2, int a[])
{
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int ptr = 0;
	for (int i = 0; i < s2.length(); i++)
	{
		while (ptr < s1.length() && s1[ptr] != s2[i]) ptr++;
		a[i] = ptr++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	string s1, s2;
	cin >> s1 >> s2;
	build(s1, s2, r);
	build(s1, s2, l);
	for (int i = 0; i < m; i++) r[i] = n - r[i] - 1;
	reverse(r, r + m);
	int ans = 0;
	for (int i = 0; i + 1 < m; i++)
		ans = max(ans, r[i + 1] - l[i]);
	printf("%d\n", ans);
	return 0;
}