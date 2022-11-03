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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int tot[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int ans = ((n - 1) / k + 1)*t;
	MEM(tot, 0);
	for (int i = t; i < N; i += t) tot[i] = k;
	for (int i = d + t; i < N; i += t) tot[i] += k;
	int ans2 = ans;
	for (int i = 1; i < N; i++)
	{
		tot[i] += tot[i - 1];
		if (tot[i] >= n)
		{
			ans2 = i;
			break;
		}
	}
	//cout << ans << ' ' << ans2 << endl;
	if (ans2 < ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}