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
int cnt[N];
int num2bin(LL x)
{
	int o = 0;
	int ret = 0;
	while (x)
	{
		if (x & 1) ret |= (1 << o);
		o++;
		x /= 10;
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(cnt, 0);
	int n;
	cin >> n;
	while (n--)
	{
		char c;
		LL num;
		cin >> c >> num;
		int x = num2bin(num);
		if (c == '+') cnt[x] ++;
		else if (c == '-') cnt[x]--;
		else cout << cnt[x] << '\n';
	}
	return 0;
}