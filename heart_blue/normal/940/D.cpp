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
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int r = 1e9, l = -1e9;
	cin >> str;
	for (int i = 1; i < n; i++)
	{
		if (str[i] == str[i - 1]) continue;
		if (str[i] == '0')
		{
			for (int j = i; j >= i - 4; j--) r = min(r, a[j] - 1);
		}
		else
		{
			for (int j = i; j >= i - 4; j--) l = max(l, a[j] + 1);
		}
	}
	printf("%d %d\n", l, r);
	return 0;
}