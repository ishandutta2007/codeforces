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
vector<int> v[2];
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[0].push_back(x);
	}
	int ans = 0;
	sort(v[0].begin(), v[0].end());
	while (!v[t].empty())
	{
		v[t ^ 1].clear();
		if (v[t].front() == v[t].back())
		{
			break;
		}
		for (int i = 1; i < v[t].size(); i++)
		{
			if (v[t][i] != v[t][i - 1])
			{
				ans++;
			}
			else
			{
				v[t ^ 1].push_back(v[t][i]);
			}
		}
		t ^= 1;
	}
	cout << ans << endl;
	return 0;
}