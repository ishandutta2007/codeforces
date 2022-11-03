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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int flag[N][N];
LL l[N];
LL r[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(flag, 0);
	MEM(l, 0);
	MEM(r, 0);
	string str;
	cin >> str;
	int n = str.length();

	for (int i = 0; i < n; i++) flag[i][i] = flag[i + 1][i] = 1;
	for (int k = 1; k < n; k++)
	{
		for (int i = 0; i + k < n; i++)
		{
			if (str[i] == str[i + k] && flag[i + 1][i + k - 1]) flag[i][i + k] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (flag[i][j]) r[i]++, l[j]++;
		}
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ans += r[j] * l[i];
		}
	}
	cout << ans << endl;
	return 0;
}