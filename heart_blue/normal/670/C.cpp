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

int a[N], b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> m;
	while (n--)
	{
		int x;
		cin >> x;
		m[x] ++;
	}
	int q;
	cin >> q;
	pair<int, int> ans = { -1, -1 };
	int key = -1;
	for (int i = 1; i <= q; i++) cin >> a[i];
	for (int i = 1; i <= q; i++) cin >> b[i];
	for (int i = 1; i <= q; i++)
	{
		pair<int, int> p = { m[a[i]],m[b[i]] };
		if (ans < p)
		{
			ans = p;
			key = i;
		}
	}
	cout << key << endl;

	return 0;
}