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
int flag[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l, r;
	string str;
	cin >> str;
	int n = str.length();
	l = 1, r = n;
	int ans = r;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		MEM(cnt, 0);
		MEM(flag, 0);
		for (int i = 0; i < mid; i++) cnt[str[i]]++;
		for (int i = 0; i < N; i++) if (cnt[i] == 0) flag[i] = 1;
		for (int i = mid; i < n; i++)
		{
			cnt[str[i]]++;
			cnt[str[i - mid]]--;
			if (cnt[str[i - mid]] == 0) flag[str[i - mid]] = 1;
		}
		int f = 0;
		for (int i = 'a'; i <= 'z'; i++)
		{
			if (flag[i] == 0)
			{
				f = 1;
				break;
			}
		}
		if (f) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}