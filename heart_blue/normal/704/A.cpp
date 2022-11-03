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
const int N = 3e5 + 10;

vector<int> v[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	int m = 0;
	int cur = 0;
	int rd = 0;
	for (int i = 0; i < q; i++)
	{
		int op, x;
		cin >> op >> x;
		if (op == 1)
		{
			v[x].push_back(m);
			flag[m++] = 1;
		}
		if (op == 2)
		{
			for (auto &y : v[x])
			{
				rd += flag[y];
				flag[y] = 0;
			}
			v[x].clear();
		}
		if (op == 3)
		{
			while (cur < x)
			{
				rd += flag[cur];
				flag[cur++] = 0;
			}
		}
		cout << m - rd << endl;
	}
	return 0;
}