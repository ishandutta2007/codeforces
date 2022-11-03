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
const int N = 9e3 + 10;
vector<int> v[N];
int last[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < N; i++)
		v[i].push_back(0);
	for (int i = 0; i < N; i++)
		last[i] = N - 1;
	ans[0] = 1;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		for (auto& o : v[x])
		{
			int val = o ^ x;
			ans[val] = 1;
			while (last[val] > x)
			{
				v[last[val]--].push_back(val);
			}
		}
		v[x].clear();
	}
	vector<int> key;
	for (int i = 0; i < N; i++)
	{
		if (ans[i])
			key.push_back(i);
	}
	printf("%d\n", key.size());
	for (auto& x : key)
		printf("%d ", x);
	return 0;
}