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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = n;
	string ans;
	int pre = -INF;
	while (l <= r)
	{
		if (max(a[l], a[r]) <= pre) break;
		if (a[l] < a[r])
		{
			if (a[l] > pre)
			{
				ans.push_back('L');
				pre = a[l++];
			}
			else
			{
				ans.push_back('R');
				pre = a[r--];
			}
			continue;
		}
		if (a[l] > a[r])
		{
			if (a[r] > pre)
			{
				ans.push_back('R');
				pre = a[r--];
			}
			else
			{
				ans.push_back('L');
				pre = a[l++];
			}
			continue;
		}
		int cnt1 = 1;
		int cnt2 = 1;
		for (int i = l + 1; i <= r; i++)
		{
			if (a[i] > a[i - 1]) cnt1++;
			else break;
		}
		for (int i = r - 1; i > 0; i--)
		{
			if (a[i] > a[i + 1]) cnt2++;
			else break;
		}
		if (cnt1 > cnt2) ans += string(cnt1, 'L');
		else ans += string(cnt2, 'R');
		break;
	}
	cout << ans.size() << endl;
	cout << ans << endl;
	return 0;
}