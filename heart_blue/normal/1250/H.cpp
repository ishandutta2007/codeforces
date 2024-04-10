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
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	LL tot = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[a[i]].push_back(x);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	int rest = 0;
	for (int i = 1; i <= k; i++)
	{
		if (v[i].empty()) rest++;
		else
		{
			sort(v[i].begin(), v[i].end());
			v[i].pop_back();
			for (auto& x : v[i])
				pq.emplace(x);
		}
	}
	LL ans = 0;
	while (rest--)
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;
	return 0;
}