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
const int N = 5e3 + 10;
bool check(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v;
	LL tota = 0;
	LL totb = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(a - b);
		totb += b;
		tota += a;
	}
	if (totb > m)
	{
		puts("-1");
		return 0;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	while (tota > m)
	{
		ans++;
		tota -= v.back();
		v.pop_back();
	}
	cout << ans << endl;
	return 0;
}