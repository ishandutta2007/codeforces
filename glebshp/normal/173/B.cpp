#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1100;
const int inf = 1000 * 1000 * 1000;

int n, m;
char field[size][size];
bool way[size * 2][size * 2];
int queue[size * 2];
int dist[size * 2];

int main() {
	//freopen("problemB.in", "r", stdin);
	//freopen("problemB.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", field[i]);
		for (int j = 0; j < m; j++)
			if (field[i][j] == '#')
			{
				way[i][n + j] = true;
				way[n + j][i] = true;
			}
	}
	int qs = 0, qf = 1, v;
	queue[0] = n - 1;
	for (int i = 0; i < n + m; i++)
		dist[i] = inf;
	dist[n - 1] = 0;
	while (qs < qf)
	{
		v = queue[qs++];
		for (int i = 0; i < n + m; i++)
			if (way[v][i] && dist[v] + 1 < dist[i])
			{
				queue[qf++] = i;
				dist[i] = dist[v] + 1;
			}
	}
	if (dist[0] > inf / 2)
		cout << -1 << endl;
	else
		cout << dist[0];

	return 0;
}