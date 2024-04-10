#include <bits/stdc++.h>

const double eps = 1e-8;
int n,s[40],cnt,m;
int det[2];
double x,y;

struct data {
	double x,y;
	int z;
};
std::vector<data>F[20][400],G[20][400];
int cmp(data a,data b) { return a.y < b.y; }

data dat(double x,double y,int z) {
	data d; d.x=x; d.y=y; d.z=z; return d;
}

double cal(double a,int wa,double b,int wb) {
	return (a * wa + b * wb) / (wa + wb);
}

int check(double cx,double cy) {
	if (std::abs(cx - x) < eps && std::abs(cy - y) < eps) return 1;
	return 0;
}

double getx(int l,int r) {
	int flag = 0;
	if (l > r) { flag = 1; std::swap(l,r); }
	double ans = (l + 1) / (double) (2 * l + 1);
	return flag ? (1 - ans) : ans;
}

double gety(int l,int r) {
	if (l > r) std::swap(l,r);
	return (3*l*l + 3 * l + 1) / (double) (6 * l + 3);
}

void dfs(int u,int h,int mass,int S,double cx,double cy) {
	if (u == m) {
		assert(mass <= m * m);
		F[h][mass].push_back(dat(cx,cy,S));
		return;
	} 
	det[0] = 1; det[1] = -1;
	for (int i = 0; i < 2; ++ i) {
		int d = det[i];
		if (h + d < 0) continue;
		double nx = getx(h,h+d) + u; 
		double ny = gety(h,h+d);
		int m = h * 2 + d;
		dfs(u+1,h+d,mass+m,S+i*(1<<u),cal(cx,mass,nx,m),cal(cy,mass,ny,m));
	}
}

int diff(double x,double y) { return std::abs(x-y) > eps; }
void check(data a,data b,int m1,int m2) {
//	printf("%.2f %.2f\n",(a.x*m1+b.x*m2)/(m1+m2),(a.y*m1+b.y*m2)/(m1+m2));
	if (diff((a.x*m1+b.x*m2)/(m1+m2),x) || diff((a.y*m1+b.y*m2)/(m1+m2),y)) return;
	int s1 = a.z, s2 = b.z;
	for (int i = 0; i < m; ++ i) {
		if (s1 & (1 << i)) printf(")");
		else printf("(");
	}
	for (int i = m - 1; i >= 0; -- i) {
		if (s2 & (1 << i)) printf("(");
		else printf(")");
	} exit(0);
}

int main() {
	scanf("%d%lf%lf",&n,&x,&y);
	m = n / 2;
	dfs(0,0,0,0,0,0);
	for (int i = 0; i <= m; ++ i) {
		for (int j = 1; j <= m * m; ++ j) {
			if (F[i][j].empty()) continue;
			for (auto p:F[i][j]) 
				G[i][j].push_back(dat(n - p.x,p.y,p.z));
			std::sort(F[i][j].begin(),F[i][j].end(),cmp);
			std::sort(G[i][j].begin(),G[i][j].end(),cmp);
		}
		for (int j = 1; j <= m * m; ++ j) {
			// p.x * j + q.x * k = x * (j + k)
			for (int k = 1; k <= m * m; ++ k) {
				if (G[i][k].empty()) continue;
				int q = G[i][k].size() - 1;
				for (auto p:F[i][j]) {
					while (q > 0 && G[i][k][q].y*k > y * (j + k) - p.y*j) q --;
					for (int l = q; l >= 0; l --) {
						check(p,G[i][k][l],j,k);
						if (q-l>7&&diff(G[i][k][l].y*k + p.y*j,y * (j + k))) break;
					}
					for (int l = q; l < G[i][k].size(); l ++) {
						check(p,G[i][k][l],j,k);
						if (l-q>7&&diff(G[i][k][l].y*k + p.y*j,y * (j + k))) break;
					}
				}
			}
		}
	}
	//assert(0);	
	return 0;
}