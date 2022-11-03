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
const int N = 2e2 + 10;
int dx[] = { 0,-1,1,-1,0,0,1 };
int dy[] = { 0,0,0,-1,-1,1,1 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	map<pair<int,int>,int> mc;
	for (int i = 1; i <= n; i++)
	{
		int x = i;
		int y = i;
		for (int o = 0; o < 7; o++)
		{
			mc[make_pair(x + dx[o], y + dy[o])] = 1;
		}
	}
	printf("%d\n", mc.size());
	for (auto& p : mc)
	{
		printf("%d %d\n", p.first.first, p.first.second);
	}
	return 0;
}