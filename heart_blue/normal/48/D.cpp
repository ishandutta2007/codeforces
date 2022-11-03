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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int flag[N];
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
	int cnt = 0;
	for (int i = N - 1; i > 0; i--)
	{
		while (!v[i].empty())
		{
			cnt++;
			for (int j = i; j > 0; j--)
			{
				if (v[j].empty())
				{
					puts("-1");
					return 0;
				}
				flag[v[j].back()] = cnt;
				v[j].pop_back();
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) printf("%d ", flag[i]);
	return 0;
}