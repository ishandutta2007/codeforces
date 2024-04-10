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
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const int size = 1000;
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};

int cnt[size * 2][size * 2];
bool used[size * 2][size * 2];

int main() {
	int n, t;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	scanf("%d%d", &n, &t);
	cnt[size][size] = n;
	queue <pair <int, int > > q;
	q.push(mp(size, size));
	used[size][size] = true;
	int mx = 0;

	while (!q.empty()) {
		pair <int, int> v = q.front();
		q.pop();
		mx = max(mx, abs(v.fs - size) + abs(v.sc - size));
		used[v.fs][v.sc] = false;
		if (cnt[v.fs][v.sc] >= 4) {
			for (int i = 0; i < 4; i++) {
				cnt[v.fs + px[i]][v.sc + py[i]] += cnt[v.fs][v.sc] / 4;
				if (!used[v.fs + px[i]][v.sc + py[i]]) {
					used[v.fs + px[i]][v.sc + py[i]] = true;
					q.push(mp(v.fs + px[i], v.sc + py[i]));
				}
			}
			cnt[v.fs][v.sc] %= 4;
		}
	}

	int x, y;
	for (int i = 0; i < t; i++) {
		scanf("%d%d", &x, &y);
		if (abs(x) + abs(y) > mx)
			printf("0\n");
		else
			printf("%d\n", cnt[x + size][y + size]);
	}
	//cout << mx << endl;

	return 0;
}