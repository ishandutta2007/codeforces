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
const int N = 2e2 + 10;
map<LL, int> m[N];
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	MEM(flag, 0);
	for (int i = 'a'; i <= 'z'; i++) cin >> a[i];
	string str;
	cin >> str;
	LL ans = 0;
	LL sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum += a[str[i]];
		if (flag[str[i]])
		{
			ans += m[str[i]][sum - a[str[i]]];
		}
		m[str[i]][sum]++;
		flag[str[i]] = 1;
	}
	cout << ans << endl;
	return 0;
}