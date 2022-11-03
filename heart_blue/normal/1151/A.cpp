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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	string a;
	int n;
	cin >> n;
	cin >> str;
	a = "ACTG";
	int ans = INF;
	for (int i = 0; i + 4 <= n; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int o = abs(str[i + j] - a[j]);
			sum += min(o, 26 - o);
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}