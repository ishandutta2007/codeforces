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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int cnt[N];
int flag[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	int r = 0;
	for (int i = 0; i < N; i++) r += cnt[i] > 0;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i]]--;
		if (cnt[a[i]] == 0) r--;
		if (!flag[a[i]])
		{
			flag[a[i]] = 1;
			ans += r;
		}
	}
	cout << ans << endl;
	return 0;
}