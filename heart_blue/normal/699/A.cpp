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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int ans = INF;
	string str;
	cin >> n;
	cin >> str;
	int pre = -1;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (i == 0)
		{
			pre = x;
			continue;
		}
		if (str[i] != str[i - 1] && str[i] == 'L')
		{
			ans = min((x - pre) / 2, ans);
		}
		pre = x;
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}