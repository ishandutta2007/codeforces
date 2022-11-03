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
map<char, int> m[N];
vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vs.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
		for (auto &c : vs[i]) m[i][c] = 1;
	}
	int ans = 0;
	for (char c1 = 'a'; c1 <= 'z'; c1++)
	{
		for (char c2 = c1+1; c2 <= 'z'; c2++)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (m[i].size() > 2) continue;
				if (m[i].size() == 1)
				{
					if (m[i].count(c1) || m[i].count(c2))
						sum += vs[i].length();
				}
				else
				{
					if (m[i].count(c1) && m[i].count(c2))
					{
						sum += vs[i].length();
					}
				}

			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}