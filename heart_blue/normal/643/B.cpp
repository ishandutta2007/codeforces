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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (n == 4 || k <= n) puts("-1");
	else
	{
		v.resize(n);
		cin >> v[0] >> v[n - 1];
		cin >> v[n - 4] >> v[n - 2];
		flag[v[0]] = flag[v[n - 1]] = flag[v[n - 4]] = flag[v[n - 2]] = 1;
		int o = 1;
		for (int i = 0; i < n; i++)
		{
			if (flag[v[i]]) continue;
			while (flag[o]) o++;
			v[i] = o++;
		}
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
		for (int i = n - 4; i >= 0; i--) cout << v[i] << ' ';
		cout << v[n - 3] << ' ' << v[n - 1] << ' ' << v[n - 2] << endl;

	}
	return 0;
}