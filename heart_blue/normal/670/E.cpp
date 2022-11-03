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
const int N = 5e5 + 10;
char str[N];
int R[N];
int L[N];
int solve(int p, int nex[])
{
	int sum = 0;
	while (1)
	{
		if (str[p] == '(') sum--;
		else sum++;
		if (sum == 0) break;
		p = nex[p];
	}
	return p;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	scanf("%s", str + 1);
	for (int i = 0; i <= n; i++) R[i] = i + 1;
	for (int i = 1; i <= n + 1; i++) L[i] = i - 1;
	string op;
	cin >> op;
	for (auto &c : op)
	{
		if (c == 'L') p = L[p];
		else if (c == 'R') p = R[p];
		else
		{
			int o;
			if (str[p] == ')') o = solve(p, L);
			else o = solve(p, R);
			if (o > p) swap(o, p);
			R[L[o]] = R[p];
			L[R[p]] = L[o];
			p = R[p];
		}
		if (p == 0) p = R[p];
		if (p == n + 1) p = L[p];
	}
	for (int i = R[0]; i <= n; i = R[i])
	{
		putchar(str[i]);

	}
	return 0;
}