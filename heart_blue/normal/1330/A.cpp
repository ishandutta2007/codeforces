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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int flag[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, x;
		cin >> n >> x;
		MEM(flag, 0);
		while (n--)
		{
			int o;
			cin >> o;
			flag[o] = 1;
		}
		int ans = 0;
		for (int i = 1; i < N && x > 0; i++)
		{
			if (flag[i]) continue;
			flag[i] = 1;
			x--;
		}
		for (int i = 1; i < N; i++)
		{
			if (flag[i]) ans = i;
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}