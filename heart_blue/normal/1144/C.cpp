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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
		if (v[x].size() > 2)
		{
			puts("NO");
			return 0;
		}
	}
	vector<int> ans;
	for (int i = 0; i < N; i++)
	{
		if (!v[i].empty())
		{
			ans.push_back(i);
			v[i].pop_back();
		}
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	cout << endl;
	cout << n - ans.size() << endl;
	for (int i = N - 1; i >= 0; i--)
	{
		if (!v[i].empty())
			cout << i << ' ';
	}
	return 0;
}