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

int n;

int x[210000];
long long sx[210000];

double calc(int m, int md) {
	long long s = x[m];
	long long mmm = x[m];

	s += sx[m-1] - sx[m-1-md];
	s += sx[n] - sx[n-md];

	double d =(s / (double)(2*md+1)) - mmm; 
	return d;
}

double test(int l1, int l2, int m, int r1, int r2, bool p=false) {
	int ls = l2-l1+1;
	int rs = r2-r1+1;

	int st = 0, ed = max(0, min(ls,rs));
	while (st+1 < ed) {
		int md = (st+ed)/2;

		double p = calc(m,md);
		double pp = calc(m,md+1);
		if (pp > p) st = md+1;
		else ed = md;
	}


	double cc = calc(m,st);
	if (ed > st) {
		double ccd = calc(m,ed);
		if (ccd > cc) {
			cc = ccd;
			st++;
		}
	}

	if (p) {
		printf("%d\n", 1 + st*2);
		for (int i = 1; i <= st; i++) printf("%d ", x[m-i]);
		printf("%d ", x[m]);
		for (int i = 1; i <= st; i++) printf("%d ", x[n+1-i]);
	}
	return cc;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}

	sort(x+1,x+n+1);

	for (int i = 1; i <= n; i++) {
		sx[i] = sx[i-1] + x[i];
	}

	double b = -1;
	int b_idx = 0;

	for (int i = 1; i <= n; i++) {
		double th = test(1, i-1, i, i+1, n);
		if (th > b) {
			b = th;
			b_idx = i;
		}
	}

	test(1,b_idx-1,b_idx,b_idx+1,n,true);
}