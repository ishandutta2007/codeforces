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
const int N = 5e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str + 1);
	for (int i = 1; i <= n && str[i]; i++)
	{
		if (k == 0) break;
		if (str[i] != '4') continue;
		//cout << i << endl;
		if (i % 2 == 1 && str[i + 1] == '4' && str[i + 2] == '7')
		{
			if (k & 1) str[i + 1] = '7';
			break;
		}
		if (i % 2 == 0 && str[i - 1] == '4' && str[i + 1] == '7')
		{
			if (k & 1) str[i] = '7';
			break;
		}
		if (str[i + 1] == '7')
		{
			if (i & 1) str[i + 1] = '4';
			else str[i] = '7', i = max(0, i - 3);
			k--;
		}
	}
	puts(str + 1);
	return 0;
}