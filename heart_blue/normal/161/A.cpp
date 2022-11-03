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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int b[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int l = 0;
	int r = 0;
	int ans = 0;
	vector<int> v;
	while (l < n && r < m)
	{
		if (a[l] - x <= b[r] && a[l] + y >= b[r])
		{
			ans++;
			l++;
			r++;
			v.push_back(l);
			v.push_back(r);
			continue;
		}
		if (a[l] - x > b[r])
		{
			r++;
			continue;
		}
		if (a[l] + y < b[r])
		{
			l++;
			continue;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < v.size(); i += 2)
	{
		cout << v[i] << ' ' << v[i + 1] << '\n';
	}
	return 0;
}