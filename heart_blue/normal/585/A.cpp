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
const int N = 4e3 + 10;
int v[N], d[N], p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i] >> d[i] >> p[i];
	vector<int> ans;
	LL power = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] < power)
		{
			power += d[i];
			continue;
		}
		LL o = power;
		ans.push_back(i + 1);
		for (int j = i + 1; j < n; j++)
		{
			if (p[j] >= o)
			{
				p[j] -= v[i]--;
			}
			else o += d[j];
			if (v[i] == 0) break;
		}
	}
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}