#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define double long double

const int size = 100 * 1000 + 100;
const double eps = 1e-12;
const double dinf = 1e9;

pair <double, double> getseg(int cur, int v, int lb, int rb) {
	if (v == 0) {
		if (lb < cur && cur < rb)
			return mp(0.0, dinf);
		else
			return mp(dinf, -dinf);
	}
	if (v < 0) {
		return getseg(-cur, -v, -rb, -lb);
	}

	if (cur <= lb) {
		return mp((double)(lb - cur) / v, (double)(rb - cur) / v); 
	}
	if (cur <= rb) {
		return mp(0.0, (double)(rb - cur) / v);
	}

	return mp(dinf, -dinf);
}

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, l, b, r, u;
    scanf("%d", &n);
    scanf("%d%d%d%d", &l, &b, &r, &u);

    double ansl = 0.0;
  	double ansr = dinf;

    for (int i = 0; i < n; i++) {

    	int x, y, vx, vy;
    	scanf("%d%d%d%d", &x, &y, &vx, &vy);
    	pair <double, double> p = getseg(x, vx, l, r);
    	ansl = max(ansl, p.fs);
    	ansr = min(ansr, p.sc);

    	p = getseg(y, vy, b, u);
    	ansl = max(ansl, p.fs);
    	ansr = min(ansr, p.sc);
    }

    cout.precision(20);
    if (ansl + eps > ansr)
    	cout << -1 << endl;
    else
    	cout << ansl << endl;

    return 0;
}