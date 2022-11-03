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
const int N = 1e5 + 10;
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
	}
	int ans = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (v[i].size() > 2)
		{
			int dif = v[i][1] - v[i][0];
			for (int j = 2; j < v[i].size(); j++)
			{
				if (v[i][j] - v[i][j - 1] != dif)
				{
					v[i].clear();
					break;
				}
			}
		}
		if (!v[i].empty()) ans++;
	}
	cout << ans << endl;
	for (int i = 0;i < N; i++)
	{
		if (!v[i].empty())
		{
			if (v[i].size() == 1) cout << i << ' ' << 0 << endl;
			else cout << i << ' ' << v[i][1] - v[i][0] << endl;
		}
	}
	return 0;
}