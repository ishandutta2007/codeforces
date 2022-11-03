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
int b[N];
int c[N];
int getans(vector<int> &v, int x)
{
	return v.rend() - upper_bound(v.rbegin(), v.rend(), x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = max(a[i], b[i - 1]);
		if (v.empty() || v.back() < a[i]) v.push_back(a[i]);
		c[i] = v.size();
	}
	v.clear();
	pair<int, int> ans = { 0,-1 };
	for (int i = n; i >= 1; i--)
	{
		int o = getans(v, b[i - 1]);
		ans = max(ans, { o + c[i - 1],-a[i] });
		while (!v.empty() && v.back() < a[i]) v.pop_back();
		v.push_back(a[i]);
	}
	cout << -ans.second << endl;
	return 0;
}