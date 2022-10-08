#pragma comment(linker, "/STACK:1000000000")
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
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 + 100;
const int inf = 1000 * 1000 * 1000;
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};

int r, c;
char field[size][size];
int dist[size][size];

bool onfield(int x, int y) {
	if (x < 0 || y < 0 || x >= r || y >= c)
		return false;

	return field[x][y] != 'T';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
		scanf("%s", field[i]);
	int xc, yc;
	for (int i = 0; i < r; i++)
		for	(int j = 0; j < c; j++) {
			dist[i][j] = inf;
			if (field[i][j] == 'E') {
				xc = i;
				yc = j;
				dist[i][j] = 0;
			}
		}
	
	queue <pair <int, int> > q;
	q.push(mp(xc, yc));
	while (!q.empty()) {
		xc = q.front().fs;
		yc = q.front().sc;
		q.pop();
		for (int i = 0; i < 4; i++)
			if (onfield(xc + px[i], yc + py[i]) && dist[xc + px[i]][yc + py[i]] > dist[xc][yc] + 1) {
				dist[xc + px[i]][yc + py[i]] = dist[xc][yc] + 1;
				q.push(mp(xc + px[i], yc + py[i]));
			}
	}

	xc = -1, yc = -1;
	int mydist;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (field[i][j] == 'S') {
				xc = i;
				yc = j;
				mydist = dist[i][j];
			}
	int ans = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (field[i][j] >= '0' && field[i][j] <= '9' && dist[i][j] <= mydist) {
				ans += (field[i][j] - '0');
			}

	cout << ans << endl;
			
    return 0;
}