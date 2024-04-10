#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Edge
{
public:
	int t, c;
};

vector < vector <Edge> > e;

int f[100] = {0};
int last;

int dfs(int x)
{
	f[x]++;
	last = x;
	int r = 0;
	for (int i = 0; i < 2; ++i)
		if (f[e[x][i].t] == 0)
			r = dfs(e[x][i].t) + e[x][i].c;
	return r;
}

int main()
{
	int n;
	cin >> n;
	int t = 0;
	e.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--;
		t += c;
		Edge dummy;
		dummy.t = y;
		dummy.c = 0;
		e[x].push_back(dummy);
		dummy.t = x;
		dummy.c = c;
		e[y].push_back(dummy);
	}
	int t1 = dfs(0);
	for (int i = 0; i < 2; ++i)
		if (e[last][i].t == 0) t1 += e[last][i].c;
	cout << min(t1, t - t1) << '\n';
	return 0;
}