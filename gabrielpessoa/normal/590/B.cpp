#include <bits/stdc++.h>
using namespace std;

int main() {
	double x1, y1, x2, y2, vmax, tvento, vx, vy, wx, wy;
	cin >> x1 >> y1 >> x2 >> y2 >> vmax >> tvento >> vx >> vy >> wx >> wy;
	vmax = vmax * vmax;
	double l = 0, r = 1000000000;
	while(l < r - 1E-6) {
		double x = x1, y = y1, t = (r+l)/2;
		x += min(t, tvento) * vx + max(0.0, t - tvento) * wx;
		y += min(t, tvento) * vy + max(0.0, t - tvento) * wy;
		double velocidade = ((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y))/(t*t);
		//cout << velocidade << " " << t << endl;
		if(velocidade  < vmax) {
			r = t;
		} else {
			l = t;
		}
	}
	printf("%.12f\n", l);
    return 0;
}