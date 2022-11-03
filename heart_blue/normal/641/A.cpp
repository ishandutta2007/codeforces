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
const int N = 1e5 + 10;
int nex[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (str[i] == '<') nex[i] = i - x;
		else nex[i] = i + x;
	}
	MEM(flag, 0);
	string ans = "FINITE";
	int cur = 0;
	while (cur >= 0 && cur < n)
	{
		if (flag[cur])
		{
			ans = "INFINITE";
			break;
		}
		flag[cur] = 1;
		cur = nex[cur];
	}
	cout << ans << endl;
	return 0;
}