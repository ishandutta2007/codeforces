#include <bits/stdc++.h>
#define N 2000500
using namespace std;

const int fx[] = {0,1,0,-1};
const int fy[] = {1,0,-1,0};

struct Point{int x,y;}o[N];
bool cmp(Point p1, Point p2) {return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;}
int x[N], y[N], tp;
inline int Abs(int x) {return x<0 ? -x : x;}
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {

	int ans = 1<<29;
	for (int i=1;i<=3;i++) x[i] = rd(), y[i] = rd();
	for (int i=0;i<=1000;i++)
		for (int j=0;j<=1000;j++) {
			int cur = 0;
			for (int _=1;_<=3;_++) cur += Abs(x[_]-i)+Abs(y[_]-j);
			cur++;
			ans = min(ans, cur);
		}

	for (int i=0;i<=1000;i++)
		for (int j=0;j<=1000;j++) {
			int cur = 0;
			for (int _=1;_<=3;_++) cur += Abs(x[_]-i)+Abs(y[_]-j);
			cur++;
			if (cur == ans) {
				for (int _=1;_<=3;_++) {
					int cx = i, cy = j;
					while (cx != x[_] || cy != y[_]) {
						o[++tp].x = cx, o[tp].y = cy;
						for (int t=0;t<4;t++) {
							int nx = cx + fx[t], ny = cy + fy[t];
							if (Abs(nx-x[_])+Abs(ny-y[_]) < Abs(cx-x[_])+Abs(cy-y[_])) {
								cx = nx;
								cy = ny;
								break;
							}
						}
					}
				}
				for (int _=1;_<=3;_++) o[++tp].x = x[_], o[tp].y = y[_];
				sort(o+1, o+tp+1, cmp);
				int cnt = tp;
				for (int _=2;_<=tp;_++) if (o[_].x == o[_-1].x && o[_].y == o[_-1].y) cnt--;
				printf("%d\n", cnt);
				for (int _=1;_<=tp;_++)
					if (_==1 || (o[_].x!=o[_-1].x || o[_].y!=o[_-1].y))
						printf("%d %d\n", o[_].x, o[_].y);
				return 0;
			}
		}
	
	return 0;
}