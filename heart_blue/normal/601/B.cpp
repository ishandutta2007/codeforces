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
LL a[N];
int L[N];
int R[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int q;
	scanf("%d", &n);
	scanf("%d", &q);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (int i = n - 1; i > 0; i--) a[i] = abs(a[i] - a[i - 1]);
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		r--;
		vector<tuple<LL, int, LL>> vp;
		LL ans = 0;
		for (int i = l; i <= r; i++)
		{
			while (!vp.empty() && get<0>(vp.back()) < a[i]) vp.pop_back();
			LL res = 0;
			if (vp.empty()) res = (i - l + 1)*a[i];
			else res = (i - get<1>(vp.back()))*a[i] + get<2>(vp.back());
			vp.push_back({ a[i],i,res });
			ans += res;
		}

		cout << ans << endl;
	}
	return 0;
}