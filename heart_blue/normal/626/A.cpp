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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int n;
	cin >> n >> str;
	auto check = [&](int l, int r) ->int
	{
		int a = 0, b = 0;
		for (int i = l; i <= r; i++)
		{
			if (str[i] == 'U') a++;
			if (str[i] == 'D') a--;
			if (str[i] == 'L') b++;
			if (str[i] == 'R') b--;
		}
		if (a == 0 && b == 0) return 1;
		else return 0;
	};
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			ans += check(i, j);
		}
	}
	cout << ans << endl;
	return 0;
}