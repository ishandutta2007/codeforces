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
vector<int> v[N];
bool check(vector<int>& v1, vector<int>& v2)
{
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		if (v1[i] < v2[i])
			cnt++;
	}
	return cnt >= 3;
}
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
		int key = 1;
		for (int i = 1; i <= n; i++)
		{
			v[i].resize(5);
			for (auto& x : v[i])
				scanf("%d", &x);
			if (i == 1) continue;
			if (check(v[i], v[key]))
				key = i;
		}
		for (int i = 1; i <= n; i++)
		{
			if (i == key) continue;
			if (check(v[i], v[key]))
			{
				key = -1;
				break;
			}
		}
		printf("%d\n", key);
	}
	return 0;
}