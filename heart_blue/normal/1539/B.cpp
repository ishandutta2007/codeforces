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
typedef unsigned long long ull;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v[200];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int q;
	scanf("%d%d", &n, &q);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
		v[str[i] - 'a' + 1].push_back(i);
	while (q--)
	{
		int ans = 0;
		int l, r;
		scanf("%d%d", &l, &r);
		for (int i = 1; i <= 26; i++)
		{
			int cnt = upper_bound(v[i].begin(), v[i].end(), r) -
				lower_bound(v[i].begin(), v[i].end(), l);
			ans += cnt * i;
		}
		printf("%d\n", ans);
	}
	return 0;
}