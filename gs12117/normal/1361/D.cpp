#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
int n, m;
int loc[500100][2];
struct st {
	long long int x, y;
	bool operator<(const st&r)const {
		return y * r.x < r.y*x; // ordered by y/x, x=0 last
	}
};
st sd[500100];
int sdl;
std::priority_queue<long double> pq;
long double dist[500100];
void solve(int l, int r) {
	int sz = 0;
	for (int i = l; i < r; i++) {
		dist[sz] = sqrt((long double)sd[i].x*sd[i].x + (long double)sd[i].y*sd[i].y);
		sz++;
	}
	std::sort(dist, dist + sz);
	int pr = sz - 1;
	int pl = 0;
	int multd = 0;
	long double sumdist = 0;
	for (int i = 0; i < sz; i++) {
		int mult = m - 2 * multd - 1;
		if (mult > 0) {
			pq.push(mult*dist[pr]);
			multd++;
			pr--;
		}
		else {
			pq.push(mult*dist[pl] - 2 * sumdist);
			sumdist += dist[pl];
			pl++;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &loc[i][0], &loc[i][1]);
	}
	pq.push(0);
	sdl = 0;
	for (int i = 0; i < n; i++) {
		if (loc[i][0] > 0 || (loc[i][0] == 0 && loc[i][1] > 0)) {
			sd[sdl].x = loc[i][0];
			sd[sdl].y = loc[i][1];
			sdl++;
		}
	}
	std::sort(sd, sd + sdl);
	for (int i = 0; i < sdl;) {
		int r = i;
		while (r < sdl && !(sd[i] < sd[r]))r++;
		solve(i, r);
		i = r;
	}
	sdl = 0;
	for (int i = 0; i < n; i++) {
		loc[i][0] = -loc[i][0];
		loc[i][1] = -loc[i][1];
		if (loc[i][0] > 0 || (loc[i][0] == 0 && loc[i][1] > 0)) {
			sd[sdl].x = loc[i][0];
			sd[sdl].y = loc[i][1];
			sdl++;
		}
	}
	std::sort(sd, sd + sdl);
	for (int i = 0; i < sdl;) {
		int r = i;
		while (r < sdl && !(sd[i] < sd[r]))r++;
		solve(i, r);
		i = r;
	}
	double ans = 0;
	for (int i = 0; i < m; i++) {
		ans += pq.top();
		pq.pop();
	}
	printf("%.20lf", ans);
	return 0;
}