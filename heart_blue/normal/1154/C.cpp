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
const int N = 5e3 + 10;
int a[7] = { 1,2,3,1,3,2,1 };
int check(vector<int> v, int cur)
{
	int ret = 0;
	for (int i = 0; i < 7; i++)
	{
		int &t = v[a[(i + cur) % 7]];
		if (t == 0) break;
		ret++;
		t--;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	int o = min({ a / 3, b / 2, c / 2 });
	int ans = o * 7;
	a -= o * 3;
	b -= o * 2;
	c -= o * 2;
	vector<int> v = { 0, a,b,c };
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		sum = max(sum, check(v, i));
	}
	cout << ans + sum << endl;
	return 0;
}