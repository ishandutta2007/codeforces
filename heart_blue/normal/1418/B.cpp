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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
int a[N];
int flag[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		LL sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &flag[i]);
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == 0)
				v.push_back(a[i]);
		}
		sort(v.rbegin(), v.rend());
		for (int i = n; i >= 1; i--)
		{
			if (flag[i]) continue;
			a[i] = v.back();
			v.pop_back();
		}
		for (int i = 1; i <= n; i++) printf("%d ", a[i]);

	}
	return 0;
}