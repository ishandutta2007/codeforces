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
const int N = 1e7 + 10;

int getdigit(int n)
{
	int ret = 0;
	if (n == 1) return 1;
	n--;
	while (n)
	{
		ret++;
		n /= 7;
	}
	return ret;
}
bool check(int i, int n)
{
	while (i)
	{
		if (i & 1) n--;
		i >>= 1;
	}
	return n == 0;
}
bool check(vector<int> &v, int s1, int s2, int n, int m)
{
	int ret1 = 0;
	int ret2 = 0;
	for (int i = 0; i < s1; i++) ret1 *= 7, ret1 += v[i];
	for (int i = s1; i < s1+s2; i++) ret2 *= 7, ret2 += v[i];
	return ret1 < n && ret2 < m;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int s1 = getdigit(n);
	int s2 = getdigit(m);
	if (s1 + s2 > 7)
	{
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < (1 << 7); i++)
	{
		if (!check(i, s1 + s2)) continue;
		vector<int> v;
		for (int j = 0; j < 7; j++) if ((1 << j)&i) v.push_back(j);
		do
		{
			if (check(v, s1, s2, n, m)) ans++;
		} while (next_permutation(v.begin(), v.end()));
	}
	cout << ans << endl;


	return 0;
}