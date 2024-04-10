#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;
typedef double kk;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef pair<kk,kk> pol;

int n,m;
pol vec[1100000];
pol tree[4100000];
int angt[1100000];
const double pi = 2*acos(0);

void sum(int a, int b) {
	while (a <= n) {
		angt[a] += b;
		a += a&-a;
	}
}

double read(int a) {
	int s = 0;
	while (a > 0) {
		s += angt[a];
		a -= a&-a;
	}
	return (s%360) * pi / 180.0;
}

pol add(pol a, pol b) {
	kk ax = a.first * cos(a.second);
	kk ay = a.first * sin(a.second);
	kk bx = b.first * cos(b.second);
	kk by = b.first * sin(b.second);
	//printf("%f %f %f %f\n", ax,ay,bx,by);
	kk kx = ax+bx;
	kk ky = ay+by;
	pol r = {sqrt(kx*kx + ky*ky), atan2(ky,kx)};

	//printf("%f %f %f %f %f %f\n", a.first, a.second, b.first, b.second, r.first, r.second);
	return r;
}

pol qry(int k, int i=1, int st=1, int ed=n) {
	if (st > k) return {0,0};
	
	if (ed <= k) return tree[i];

	int md = (st+ed)/2;

	double sa = read(md+1) - read(st);
	pol a = qry(k,2*i,st,md);
	pol b = qry(k,2*i+1,md+1,ed);
	b.second += sa;
	return add(a,b);
}

void upd(int k, int i=1, int st=1, int ed=n) {
	if (st > k || ed < k) return;
	if (st == k && ed == k) {
		tree[i] = vec[st];
		return;
	}

	int md = (st+ed)/2;
	upd(k,2*i,st,md);
	upd(k,2*i+1,md+1,ed);

	double sa = read(md+1) - read(st);

	pol temp = tree[2*i+1];
	temp.second += sa;
	pol ret = add(tree[2*i], temp);
	//printf("%f %d %d %d %f %f %f %f %f %f\n", sa,i,st,ed,tree[2*i].first, tree[2*i].second,temp.first, temp.second,ret.first,ret.second);
	tree[i] = ret;
}

void pt(int i=1, int st=1, int ed=n) {
	printf("%d %d %f %f\n", st, ed, tree[i].first, tree[i].second);
	if (st == ed) return;
	int md = (st+ed)/2;
	pt(2*i,st,md);
	pt(2*i+1,md+1,ed);
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		vec[i] = {1,0};
		upd(i);
	}

	for (int i = 0; i < m; i++) {
		int typ, seg, par;
		scanf("%d %d %d", &typ, &seg, &par);

		if (typ == 1) {
			vec[seg].first += par;
		}
		else {
			sum(seg, -par);
		}
		upd(seg);

		pol a = qry(n);
		//pt();
		//printf("\n");
		//printf("%f %f\n", a.first, a.second);
		a.second += read(1);
		printf("%.10f %.10f\n", (double)(a.first * cos(a.second)), (double)(a.first * sin(a.second)));
	}

}