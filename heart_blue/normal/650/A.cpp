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
map<int, int> m1, m2;
map<pair<int, int>, int> mp;
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int a, b;
	cin >> n;
	LL ans = 0;
	while (n--)
	{
		cin >> a >> b;
		m1[a]++;
		m2[b]++;
		mp[{a, b}]++;
	}
	for (auto iter : m1) ans += (LL)iter.second *(iter.second - 1) / 2;
	for (auto iter : m2) ans += (LL)iter.second *(iter.second - 1) / 2;
	for (auto iter : mp) ans -= (LL)iter.second *(iter.second - 1) / 2;
	cout << ans << endl;
	return 0;
}