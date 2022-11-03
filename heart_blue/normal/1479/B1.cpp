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
const int N = 2e5 + 10;
vector<int> v[N];
int a[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
	}
	for (int i = 0; i <= n; i++) v[i].push_back(INF);
	int ans = 0;
	int o1 = 0, o2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (o1 == a[i])
		{
			if (o2 != a[i]) ans++;
			o2 = a[i];
			continue;
		}
		if (o2 == a[i])
		{
			if (o1 != a[i]) ans++;
			o1 = a[i];
			continue;
		}
		ans++;
		int key1 = *upper_bound(v[o1].begin(), v[o1].end(), i);
		int key2 = *upper_bound(v[o2].begin(), v[o2].end(), i);
		if (key1 < key2) o1 = a[i];
		else o2 = a[i];
	}
	printf("%d\n", ans);
	return 0;
}