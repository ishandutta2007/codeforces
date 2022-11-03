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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	MEM(a, 0);
	while (n--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		a[l]++;
		a[r + 1]--;
	}
	vector<int> v;
	int sum = 0;
	for (int i = 1; i < N; i++)
	{
		sum += a[i];
		if (sum >= k)
			v.push_back(i);
	}
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l));
	}
	return 0;
}