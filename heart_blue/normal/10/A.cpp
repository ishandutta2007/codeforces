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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))

const int INF = 1e6 + 3;
const int N = 2e3 + 1;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p1, p2, p3, t1, t2;
	int minv = INF;
	int maxv = 0;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	MEM(a, 0);
	t2 += t1;
	vector<int> v(n * 2);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i * 2] >> v[i * 2 + 1];
		ans += v[i * 2 + 1] - v[i * 2];
	}
	ans *= p1;
	for (int i = 2; i < n*2; i += 2)
	{
		int t = v[i] - v[i - 1];
		if (t >= t2) ans += (t - t2)*p3, t = t2;
		if (t >= t1) ans += (t - t1)*p2, t = t1;
		ans += t*p1;
	}
	cout << ans <<endl;
	return 0;
}