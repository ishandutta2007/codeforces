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
const int N = 7e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	str += str;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (1)
		{
			if (j + 1 < min(i + n, n * 2) && str[j + 1] != str[j]) j++;
			else break;
		}
		ans = max(ans, j - i + 1);
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}