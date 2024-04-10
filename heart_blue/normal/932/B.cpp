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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
vector<int> v[10];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < N; i++)
	{
		if (i < 10) a[i] = i;
		else
		{
			int x = 1;
			int o = i;
			while (o)
			{
				x *= max(o % 10, 1);
				o /= 10;
			}
			a[i] = a[x];
		}
		v[a[i]].push_back(i);
	}
	int n;
	scanf("%d", &n);
	int l, r, k;
	while (n--)
	{
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", upper_bound(v[k].begin(), v[k].end(), r) - lower_bound(v[k].begin(), v[k].end(), l));
	}
	return 0;
}