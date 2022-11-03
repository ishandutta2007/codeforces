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
const int N = 2e5 + 10;
int a[6][6];
int dp[2][6];
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	MEM(a, -1);
	for (int i = 0; i < q; i++)
	{
		string str;
		char c;
		cin >> str >> c;
		a[str[0] - 'a'][str[1] - 'a'] = c - 'a';
	}
	int t = 0;
	for (int i = 0; i < 6; i++) dp[t][i] = 1;
	for (int i = 1; i < n; i++)
	{
		t ^= 1;
		MEM(dp[t], 0);
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				if (a[j][k] == -1) continue;
				dp[t][a[j][k]] += dp[t ^ 1][j];
			}
		}
	}
	cout << dp[t][0] << endl;
	return 0;
}