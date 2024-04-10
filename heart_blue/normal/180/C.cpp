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
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	MEM(cnt, 0);
	for (int i = 0; i < n; i++)
	{
		if (islower(str[i])) cnt[i] = 1;
		if (i > 0) cnt[i] += cnt[i - 1];
	}
	int ans = min(cnt[n - 1], n - cnt[n - 1]);
	int sum = 0;
	for (int i = n - 1; i > 0; i--)
	{
		if (isupper(str[i])) sum++;
		ans = min(ans, cnt[i - 1] + sum);
	}
	cout << ans << endl;

	return 0;
}