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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 9;
const int N = 2e3 + 10;
LL getans(LL a, LL b, int op)
{
	if (op == '*') return a * b;
	else return a + b;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 4;
	vector<LL> v(n);
	for (auto &x : v) cin >> x;
	string op(3, '0');
	for (auto &x : op) cin >> x;
	sort(v.begin(), v.end());
	LL ans = INF * INF;
	do
	{
		vector<LL> vv = { getans(v[0],v[1],op[0]),v[2],v[3] };
		sort(vv.begin(), vv.end());
		do
		{
			LL sum = vv[0];
			for (int i = 1; i < 3; i++)
			{
				sum = getans(sum, vv[i], op[i]);
			}
			ans = min(ans, sum);
		} while (next_permutation(vv.begin(), vv.end()));
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}