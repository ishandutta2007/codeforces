#include <bits/stdc++.h>
#define N 505
#define INF 1000
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
struct HbFS{int x,y,w,s,v;}p[N];
bool cmp(HbFS p1, HbFS p2) {return p1.y == p2.y ? p1.x > p2.x : p1.y < p2.y;}
int n,S,F[N][INF+5],f[INF+5];
int main() {
	n = rd(), S = rd();
	for (int _=1;_<=n;_++)
		p[_].x = rd(), p[_].y = rd(),
		p[_].w = rd(), p[_].s = rd(),
		p[_].v = rd();
	p[++n] = (HbFS){0, INF, 0, S, 0};

	sort(p+1,p+n+1,cmp);
	for (int _=1;_<=n;_++) {
		for (int i=p[_].w;i<=S;i++) {
			int tp = 0, nw = min(p[_].s, i-p[_].w);
			for (int j=0;j<_;j++) if (p[j].x >= p[_].x) {
				while (tp < p[j].y) f[tp+1] = f[tp], ++tp;
				f[tp] = max(f[tp], f[p[j].x] + F[j][nw]);
			}
			F[_][i] = f[tp] + p[_].v;
			for (int j=0;j<=tp;j++) f[tp] = 0;
		}
	}
	cout << F[n][S] << endl;
	return 0;
}