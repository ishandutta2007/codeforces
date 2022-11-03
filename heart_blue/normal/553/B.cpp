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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 51;
LL f[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	f[0] = 0, f[1] = 1, f[2] = 2;
	for (int i = 3; i < N; i++) f[i] = f[i - 1] + f[i - 2];
	int n;
	LL k;
	cin >> n >> k;
	int cur = 1;
	for (int i = n; i > 1; i--)
	{
		if (k > f[i - 1])
		{
			cout << cur + 1 << ' ' << cur << ' ';
			k -= f[i - 1];
			i--;
			cur += 2;
		}
		else cout << cur++ << ' ';
	}
	if (cur == n) cout << cur;
	return 0;
}