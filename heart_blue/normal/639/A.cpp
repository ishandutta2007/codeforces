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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q, k;
	vector<int> v;
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	auto cmp = [&](int x, int y) -> bool
	{
		return a[x] > a[y];
	};
	while (q--)
	{
		int type, id;
		cin >> type >> id;
		if (type == 1)
		{
			if (v.size() <= k) v.push_back(id);
			else v[k] = id;
			sort(v.begin(), v.end(), cmp);
		}
		else
		{
			int flag = 0;
			int o = min(k, (int)v.size());
			for (int i = 0; i < o; i++)
			{
				if (v[i] == id) flag = 1;
			}
			if (flag) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}