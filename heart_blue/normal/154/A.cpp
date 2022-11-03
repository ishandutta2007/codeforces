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
int ans[N];
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l = 'a';
	int r = 'z';
	for (int i = l; i <= r; i++)
	{
		for (int j = l; j <= r; j++)
		{
			flag[i][j] = 1;
		}
	}
	MEM(ans, 0);
	string str;
	cin >> str;
	int n = str.length();
	int q;
	cin >> q;
	while (q--)
	{
		string s;
		cin >> s;
		char c1 = s[0], c2 = s[1];
		flag[c1][c2] = flag[c2][c1] = 0;
	}
	for (auto &c : str)
	{
		int sum = 0;
		for (int i = l; i <= r; i++)
		{
			if (flag[c][i])
				sum = max(sum, ans[i]);
		}
		ans[c] = max(ans[c], sum + 1);
	}
	int res = 0;
	for (int i = l; i <= r; i++) res = max(res, ans[i]);
	cout << n - res << endl;
	return 0;
}