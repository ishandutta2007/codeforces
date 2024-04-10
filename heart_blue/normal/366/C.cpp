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
const int N = 1e4 + 10;
bitset<N> b[N];
int a[N];
int w[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> w[i];
	b[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = N - 1; j >= a[i]; j--)
		{
			b[j] |= b[j - a[i]] << w[i];
		}
	}
	int ans = -1;
	for (int i = k; i < N; i+=k)
	{
		if (b[i][i / k])
		{
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}