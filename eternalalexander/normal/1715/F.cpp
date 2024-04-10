#include <bits/stdc++.h>

using ld = long double;
const ld eps = 1e-10;
int n,m;

std::vector<std::pair<ld,ld> >qr;

int equal(ld a,ld b) { return std::abs(a - b) < eps; }

ld query(std::vector<std::pair<ld,ld> >q,ld det) {
	printf("? %d\n",q.size());
	for (auto p:q) {
		ld x = p.first, y = p.second;
		printf("%.15Lf %.15Lf\n",x+det,y);
	}
	fflush(stdout);
	ld res;
	scanf("%Lf",&res);
	return res;
}

int main() {
	scanf("%d%d",&n,&m); n += 4; //m += 10;
	qr.push_back({0,-10});
	for (int i = 0; i < n; ++ i) {
		if (i % 2) qr.push_back({i+1,-1});
		else {
			qr.push_back({i,m});
			qr.push_back({i+1,m});
			qr.push_back({i+1,-1});
		}
	} ld S1 = query(qr,0);
	ld det = -S1;
	ld g = query(qr,det);
	if (!(equal(g,1) || equal(g,0) )) det = -1+S1;
	//printf("det = %.4Lf\n",det);
	qr.clear();
	qr.push_back({0,-1});
	ld L = 1 / (ld)n;
	ld H = m;
	ld delta = L / H;
	for (int i = 0; i < n; ++ i) {
		qr.push_back({i,0});
		qr.push_back({i,m});
		if (i) qr.push_back({i+L*i,m});
		qr.push_back({i+L*(i+1),0});
	} qr.push_back({n,0});
	qr.push_back({n,-1});
	ld S2 = query(qr,det);
	//S2 = (x+x-delta)/2 -> 2x-delta = 2S2 -> x = (2S2 + delta) / 2
	ld l = (2 * S2 + delta) / 2;
//	printf("upper = %.5Lf, delta = %.5Lf,S=%.5Lf\n",l,delta,l*(l-delta)/2);
	ld x = std::floor(l / L - eps*10);
	ld y = m * (1 - ((l - L * x) / L));
	printf("! %.10Lf %.10Lf",x+det,y);
	fflush(stdout);
	return 0;
}