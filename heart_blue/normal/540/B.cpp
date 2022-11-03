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
const LL INF = 1e9 + 7;
const int N = 5e2+10;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	int l = n / 2;
	int r = n / 2 + 1;
	int sum = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < k; i++)
	{
		int t;
		cin >> t;
		sum += t;
		if (t >= y) cnt2++;
		else cnt1++;
	}
	if (cnt1 > l)
	{
		cout << -1 << endl;
		return 0;
	}
	if (cnt2 > r)
	{
		cnt1 += cnt2 - r;
		cnt2 = r;
	}
	if (sum + l - cnt1 + (r - cnt2)*y > x)
	{
		cout << -1 << endl;
		return 0;
	}
	while (cnt1++ < l) cout << 1 << ' ';
	while (cnt2++ < r) cout << y << ' ';

	return 0;
}