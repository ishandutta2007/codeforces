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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	map<int, int> mm;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (mm.count(x)) mm[x] = -i;
		else mm[x] = i;
	}
	vector<int> ans;
	int flag = 0;
	while (m--)
	{
		int x;
		cin >> x;
		if (!mm.count(x))
		{
			cout << "Impossible" << endl;
			return 0;
		}
		else
		{
			ans.push_back(mm[x]);
			if (ans.back() < 0) flag = 1;
		}
	}
	if (flag) cout << "Ambiguity" << endl;
	else
	{
		cout << "Possible" << endl;
		for (auto &x : ans) cout << x << ' ';
	}
	return 0;
}