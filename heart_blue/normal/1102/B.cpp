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
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int ans[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
		if (v[x].size() > k)
		{
			puts("NO");
			return 0;
		}
	}
	int cur = 1;
	for (int i = 1; i < N; i++)
	{
		while (!v[i].empty())
		{
			ans[v[i].back()] = cur++;
			if (cur > k) cur -= k;
			v[i].pop_back();
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}