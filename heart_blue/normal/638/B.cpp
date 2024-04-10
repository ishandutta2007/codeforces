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
const int N = 2e2 + 10;
int nex[N];
int deg[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(nex, -1);
	while (n--)
	{
		string str;
		cin >> str;
		for (auto &c : str) flag[c] = 1;
		for (int i = 0; i + 1 < str.length(); i++)
		{
			nex[str[i]] = str[i + 1];
			deg[str[i + 1]] = 1;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (flag[i] == 0 || deg[i] == 1) continue;
		int x = i;
		while (1)
		{
			putchar(x);
			x = nex[x];
			if (x == -1) break;
		}
	}
	return 0;
}