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
const int N = 5e5 + 10;
int a[N];
vector<int> v[N];
LL ans = 0;
int cnt = 0;
void check(string& str)
{
	int o = 0;
	int minv = 0;
	for (auto& c : str)
	{
		if (c == '(') o++;
		else o--;
		minv = min(minv, o);
	}
	if (o == 0 && minv == 0) cnt++;
	if (o > 0 && minv == 0) a[o]++;
	if (o < 0) v[-o].push_back(-minv);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		check(str);
	}
	for (int i = 1; i < N; i++)
	{
		if (a[i] == 0) continue;
		if (v[i].empty()) continue;
		sort(v[i].begin(), v[i].end());
		ans += min(a[i], int(upper_bound(v[i].begin(), v[i].end(), i) - v[i].begin()));
	}
	cout << ans + cnt / 2;
	return 0;
}