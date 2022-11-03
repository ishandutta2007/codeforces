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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e8 + 7;
const int N = 2e3 + 10;
int cnt[N][128];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (n--)
	{
		string str;
		cin >> str;
		for (int i = 0; i < m; i++) cnt[i][str[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		int maxv = 0;
		for (int j = 'A'; j <= 'E'; j++)
			maxv = max(maxv, cnt[i][j]);
		ans += maxv * x;
	}
	cout << ans << endl;
	return 0;
}