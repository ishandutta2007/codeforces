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
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int sum[2] = { 0,0 };
	int n, m;
	cin >> n;
	vector<int> v;
	while (n--)
	{
		cin >> m;
		for (int i = 1; i <= m; i++) cin >> a[i];
		int l = 1, r = m;
		while (l < r) sum[0] += a[l++], sum[1] += a[r--];
		if (l == r) v.push_back(a[l]);
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++) sum[i & 1] += v[i];
	cout << sum[0] << ' ' << sum[1] << endl;
	return 0;
}