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
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 1e4 + 10;
int nex[N][200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	MEM(nex[0], -1);
	for (int i = 0; i < s1.length(); i++)
	{
		if (nex[0][s1[i]] == -1) nex[0][s1[i]] = i + 1;
	}
	for (int i = 1; i <= s1.length(); i++)
	{
		memcpy(nex[i], nex[0], sizeof(nex[0]));
	}
	for (int i = s1.length() - 2; i >= 0; i--)
	{
		memcpy(nex[i + 1], nex[i + 2], sizeof(nex[0]));
		nex[i + 1][s1[i + 1]] = i + 2;
	}
	int cur = 0;
	int ans = 1;
	for (auto &c : s2)
	{
		if (nex[cur][c] == -1)
		{
			ans = -1;
			break;
		}
		if (cur >= nex[cur][c]) ans++;
		cur = nex[cur][c];
	}
	cout << ans << endl;

	return 0;
}