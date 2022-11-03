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
const int INF = 1e9 + 3;
const int N = 4e5 + 10;
int getans(int n)
{
	int ret = 0;
	while (n)
	{
		ret++;
		n -= n&-n;
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	int n, m, k;
	cin >> n >> m >> k;
	m++;
	v.resize(m);
	for (auto &x : v) cin >> x;
	int ans = 0;
	for (int i = 0; i < m-1; i++)
	{

			if (getans(v[i] ^ v[m-1]) <= k) ans++;

	}
	cout << ans << endl;
	return 0;
}