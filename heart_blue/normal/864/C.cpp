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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, f, k;
	cin >> a >> b >> f >> k;
	vector<int> v;
	v.push_back(f);
	for (int i = 1; i < k; i++)
	{
		if (i & 1) v.push_back((a - f) * 2);
		else v.push_back(2 * f);
	}
	if (k & 1) v.push_back(a - f);
	else v.push_back(f);
	int maxn = *max_element(v.begin(), v.end());
	if (maxn > b)
	{
		puts("-1");
		return 0;
	}
	LL cur = b;
	int cnt = 0;
	for (auto &x : v)
	{
		if (cur >= x) cur -= x;
		else cur = b - x, cnt++;
	}
	cout << cnt << endl;

	return 0;
}