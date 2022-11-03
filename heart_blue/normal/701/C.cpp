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
const int N = 2e2 + 10;
int flag[N];
string str;
bool check(int x, int tot)
{
	int l = 0;
	int r = x;
	int sum = 0;
	int cnt[N];
	int n = str.length();
	MEM(cnt, 0);
	for (int i = l; i < r; i++)
	{
		if (cnt[str[i]] == 0) sum++;
		cnt[str[i]]++;
	}
	if (sum == tot) return true;
	while (r < n)
	{
		if (cnt[str[l]] == 1) sum--;
		cnt[str[l]]--;
		if (cnt[str[r]] == 0) sum++;
		cnt[str[r]]++;
		l++, r++;
		if (sum == tot) return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cin >> str;
	int tot = 0;
	MEM(flag, 0);
	for (auto c : str)
	{
		if (!flag[c]) tot++;
		flag[c] = 1;
	}
	int l = tot;
	int r = n;
	int ans = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid, tot)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}