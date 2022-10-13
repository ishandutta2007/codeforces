#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int oo =27081993;

int n, type[100100], next[100100], d[100100], deg[100100];

int visit(int x)
{
	if (type[x]) return d[x] = 1;
	if (!x || deg[x] != 1) return d[x] = -oo;
	if (d[x]) return d[x];
	d[x] = -oo;
	if (!d[next[x]]) visit(next[x]);
	return d[x] = d[next[x]] + 1;	
}

int main()
{
	int x;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> type[i];
	for (int i = 1; i <= n; i++) 
	{
		cin >> x;
		next[x] = i;
		deg[x]++;
	}
	
	int ans = 0, start;
	for (int i = 1; i <= n; i++)
		if (visit(i) > ans)
			ans = visit(i), start = i;
	
	cout << ans << endl;
	for (int i = 0; i < ans; i++, start = next[start]) cout << start << ' ';
}