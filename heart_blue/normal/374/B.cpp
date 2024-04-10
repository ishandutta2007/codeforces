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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	ULL ans = 1;
	int cnt = 1;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] - '0' == 9 - (str[i - 1] - '0'))
		{
			cnt++;
		}
		else
		{
			if (cnt & 1) ans *= (cnt + 1) / 2;
			cnt = 1;
		}
	}
	if (cnt & 1) ans *= (cnt + 1) / 2;
	cout << ans << endl;
	return 0;
}