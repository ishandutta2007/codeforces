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
const int N = 1e6 + 10;
int pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	string str;
	cin >> k >> str;
	str = "1" + str;
	int n = str.length();
	for (int i = 0; i <= n; i++)
	{
		if (str[i] == '1') pre[i] = i;
		else pre[i] = pre[i - 1];
	}
	int p = 1;
	int cnt = 0;
	LL ans = 0;
	for (int i = 1; i < n; i++)
	{
		while (p < n && cnt + str[p] - '0' <= k)
		{
			cnt += str[p] - '0';
			p++;
		}
		if (cnt == k)
		{
			ans += p - max(pre[p - 1], i);
		}
		cnt -= str[i] - '0';
	}
	cout << ans << endl;
	return 0;
}