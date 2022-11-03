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
string str = "codeforces";
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	cin >> n;
	int len = str.length();
	for (int i = 0; i < len; i++)
		cnt[i] = 1;
	LL ans = 1;
	while (ans < n)
	{
		for (int i = 0; i < len && ans < n; i++)
		{
			ans /= cnt[i]++;
			ans *= cnt[i];
		}
	}
	for (int i = 0; i < len; i++)
		cout << string(cnt[i], str[i]);
	return 0;
}