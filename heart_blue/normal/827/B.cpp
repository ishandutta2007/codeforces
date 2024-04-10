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
typedef pair<int, int> Node;
priority_queue<Node, vector<Node>, greater<Node>> pq;
char str[N * 100];
bool check(int n, int k, int d)
{
	int rest = n - k;
	k -= 2;
	rest -= d - 1;
	int ratio = d / 2 - 1;
	return k * ratio >= rest;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int d = 0;
	for (int i = 2; i <= n; i++)
	{
		if (check(n, k, i))
		{
			d = i;
			break;
		}
	}
	printf("%d\n", d);
	for (int i = 1; i <= d; i++) printf("%d %d\n", i, i + 1);
	k -= 2;
	int cur = d + 2;
	int key = d / 2 + 1;
	for (int i = 0; i < k; i++)
	{
		printf("%d %d\n", key, cur + i);
	}
	for (int i = cur + k; i <= n; i++)
	{
		printf("%d %d\n", i - k, i);
	}
	
	return 0;
}