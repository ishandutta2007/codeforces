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
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	n *= m;
	map<int, int> mi;
	vector<int> v;
	while (n--)
	{
		int x;
		cin >> x;
		mi[x%k] = 1;
		v.push_back(x / k);
	}
	if (mi.size() != 1) 
		cout << -1 << endl;
	else 
	{
		int ans = INF;
		for (auto &x : v)
		{
			int sum = 0;
			for (auto &y : v)
			{
				sum += abs(y - x);
			}
			ans = min(ans, sum);
		}
		cout << ans << endl;
	}
	return 0;
}