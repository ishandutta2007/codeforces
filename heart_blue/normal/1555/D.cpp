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
const int N = 2e5 + 10;
char str[N];
vector<int> v[200][3];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
	{
		v[str[i]][i % 3].push_back(i);
	}
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		string str = "abc";
		int ans = 0;
		do
		{
			int sum = 0;
			for (int i = 0; i < 3; i++)
			{
				auto& vp = v[str[i]][i];
				sum += upper_bound(vp.begin(), vp.end(), r) -
					lower_bound(vp.begin(), vp.end(), l);
			}
			ans = max(ans, sum);
		} while (next_permutation(str.begin(), str.end()));
		printf("%d\n", r - l + 1 - ans);
	}
	return 0;
}