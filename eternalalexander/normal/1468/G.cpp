#include <bits/stdc++.h>

#define maxn 1000005
using ll = long long;

double ans = 0;
int n;
ll H,x[maxn],y[maxn],X,Y;

double length(ll x1,ll y1,ll x2,ll y2) {
	return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
}

struct point {
	double x,y;
};

point PT(double x,double y) { point P = {x,y}; return P; }

struct LINE {
	ll x1,y1,x,y;
};

LINE get_LINE(ll x1,ll y1,ll x2,ll y2) {
	LINE L; L.x1 = x1; L.y1 = y1; L.x = x2 - x1; L.y = y2 - y1;
	return L;
}

int OVER(LINE L1, LINE L2) {
	return L1.y * L2.x < L2.y * L1.x;
}

int PARA(LINE L1,LINE L2) {
	if (L1.x * L2.y == L1.y * L2.x) {
		ll D1 = X - L1.x1;
		ll D2 = Y - L1.y1;
	//	printf(">%lld %lld %lld %lld %lld %lld",L1.x1,L1.y1,D1,D2,L2.x,L2.y);
		if (D1 * L2.y == D2 * L2.x) return 1;
		else return -1;
	}
	return 0;
}

point intersect(LINE L1,LINE L2) {
	
	double k1 = (double) L1.y / L1.x;
	double k2 = (double) L2.y / L2.x;
	double b1 = L1.y1 - k1 * L1.x1;
	double b2 = L2.y1 - k2 * L2.x1;
	double x = (b2 - b1) / (k1 - k2);
	double y = k1 * x + b1;
	return PT(x,y);
}


int main() {
	scanf("%d%lld",&n,&H);
	for (int i = 1; i <= n; ++ i) scanf("%lld%lld",&x[i],&y[i]);
	X = x[n], Y = y[n] + H;
	ans += length(x[n-1],y[n-1],x[n],y[n]);
	LINE L = get_LINE(x[n-1],y[n-1],X,Y);
	for (int i = n - 1; i > 1; i --) {
		LINE L1 = get_LINE(x[i-1],y[i-1],x[i],y[i]);
	//	printf("[%lld %lld] [%lld %lld]\n",L1.x,L1.y,L.x,L.y);
		//printf(">%d\n",PARA(L,L1));
		double LENGTH = length(x[i-1],y[i-1],x[i],y[i]);
		double Q = 0;
		int d = PARA(L1,L);
		if (d) {
			//printf("<%d>\n",d);
			ans += (d == 1) * LENGTH;
			continue;
		}
		point P = intersect(L,L1);
	//	printf("[%lld %lld] %.2f %.2f\n",x[i-1],x[i],P.x,P.y);
		LINE Lp = get_LINE(x[i-1],y[i-1],X,Y);
		LINE Lq = get_LINE(x[i],y[i],X,Y);
	//	printf("[%lld %lld] [%lld %lld]\n",Lp.x,Lp.y,L.x,L.y);
	int c  = 0;
		if (OVER(Lp,L)) { Q = std::max(0.0,P.x - x[i-1]) / (double) (x[i] - x[i-1]);  c++; }
		if (OVER(Lq,L)) { Q = std::max(0.0,x[i] - P.x) / (double) (x[i] - x[i-1]); c++; }
		assert(c < 2);
	//	printf("Q = %.2f\n",Q);
		ans += Q * LENGTH;
		LINE L2 = get_LINE(x[i-1],y[i-1],X,Y);
		if (OVER(L2,L)) { L = L2;  }
	}
	printf("%.10f",ans);
	return 0;
}