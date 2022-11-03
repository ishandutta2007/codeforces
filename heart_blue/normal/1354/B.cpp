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
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e2 + 10;
const LL INF = 1e9 + 7;
vector<int> v[4];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		v[1].clear();
		v[2].clear();
		v[3].clear();
		for (int i = 0; i < str.length(); i++)
			v[str[i] - '0'].push_back(i);
		v[1].push_back(INF);
		v[2].push_back(INF);
		v[3].push_back(INF);
		int ans = INF;
		for (int i = 0; i < str.length(); i++)
		{
			int maxv = 0;
			for (int j = 1; j <= 3; j++)
			{
				maxv = max(maxv, *lower_bound(v[j].begin(), v[j].end(), i));
			}
			ans = min(ans, maxv - i + 1);
		}
		if (ans > str.length()) ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}