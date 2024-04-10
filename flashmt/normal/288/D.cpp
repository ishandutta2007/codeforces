#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 100100;

int n, node[N];
unsigned long long ans;
vector <int> a[N];

void calc(int x, int par)
{
	long long pathDown = 0, sumChildPath = 0;
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y == par) continue;
		calc(y, x);
		pathDown += 1LL * node[x] * node[y];
		node[x] += node[y];
		long long childPath = 1LL * node[y] * (node[y] - 1) / 2;
		ans -= childPath * sumChildPath;
		sumChildPath += childPath;
	}
		
	pathDown += node[x]++;
	long long pathUp = 1LL * (n - node[x]) * (n - node[x] - 1) / 2;
	ans += pathDown * pathUp;
}

int main()
{
	int x, y;
	cin >> n;
	for (int i = 1; i < n; i++) 
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	calc(1, 0);
	cout << ans * 2 << endl;
}