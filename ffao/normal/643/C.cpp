#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


class ConvexHullTrick {
	struct CHTPoint {
		double x, y;
		int idx;
		double lim;
	};

	std::vector<CHTPoint> pilha;
	
	inline double get_intersection(CHTPoint a, CHTPoint b);
	bool ccw(CHTPoint p0, CHTPoint p1, CHTPoint p2);
public:
	void add_line(double a, double b, int idx);
	std::pair<int, double> get_maximum(double x);
};

inline double ConvexHullTrick::get_intersection(CHTPoint a, CHTPoint b) {
	double denom = (double(b.x) - a.x);
	double num = (double(b.y) - a.y);

	return -num / denom;
}

bool ConvexHullTrick::ccw(CHTPoint p0, CHTPoint p1, CHTPoint p2) {
	return ((p1.y - p0.y)*(p2.x - p0.x) > (p2.y - p0.y)*(p1.x - p0.x));
}

void ConvexHullTrick::add_line(double a, double b, int idx) {
	CHTPoint novo = { a, b, idx, 0 };
	int tam = pilha.size();
	while (tam >= 2 && !ccw(pilha[tam - 2], pilha[tam - 1], novo)) {
		pilha.pop_back();
		tam--;
	}
	while (tam >= 1 && fabs(pilha[tam - 1].x - a) < 1e-8) {
		pilha.pop_back();
		tam--;
	}

	pilha.push_back(novo);
	if (tam >= 1) pilha[tam - 1].lim = get_intersection(pilha[tam - 1], pilha[tam]);
}

std::pair<int, double> ConvexHullTrick::get_maximum(double x) {
	int st = 0, ed = pilha.size() - 1;
	while (st < ed) {
		int mid = (st + ed) / 2;
		if (pilha[mid].lim < x) st = mid + 1;
		else ed = mid;
	}

	return std::make_pair(pilha[st].idx, pilha[st].x * x + pilha[st].y);
}

double reprsum[210000];
double cost[51][210000];
int t[210000];
long long soma[210000];

int n, k;
void solve() {
	scanf("%d %d", &n, &k);
	REP(i,n) {
		scanf("%d", &t[i]);
		soma[i+1] = soma[i] + t[i];
		reprsum[i+1] = reprsum[i] + 1.0/t[i];
	}

	REP(i,n) {
		cost[1][i] = soma[i+1]/(double)t[i];
		if (i > 0) cost[1][i] += cost[1][i-1];

		//printf("cost[1][%d] = %f\n", i, cost[1][i]);
	}

	for (int regs=2; regs <= k; regs++) {
		ConvexHullTrick cht;

		double curr = 0;
		for (int idx = 0; idx < n; idx++) {
			curr += 1.0/t[idx];

			double b = -soma[idx]*curr; 
			if (idx > 0) b -= (cost[regs-1][idx-1] - cost[1][idx]);

			//printf("line from %d is a = %f, b = %f\n", idx, (double)soma[idx], b);
			cht.add_line(soma[idx], b, idx);
			
			int bst = cht.get_maximum(curr).first;

			//printf("optimal comes from %d\n", bst);
			cost[regs][idx] =  ( cost[1][idx] - (bst==0 ? 0 : cost[1][bst-1]) ) - soma[bst] * (reprsum[idx+1] - reprsum[bst]) ;
			if (bst > 0) cost[regs][idx] += cost[regs-1][bst-1];
		}
	}

	printf("%.15f\n", cost[k][n-1]);
}

int main() {
    solve();
}