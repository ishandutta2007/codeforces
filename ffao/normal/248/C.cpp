    #include <bits/stdc++.h>
    using namespace std;
    using ld = long double;
    ld yl, yt, yw, xb, yb, rad;
     
    ld dist(ld x, ld y) {
    	ld a = (yw - yb) / (xb - x);
    	ld c = yw - a * x;
     
    	return abs(c - y) / sqrtl(a * a + 1.0);
    }
     
    int main() {
    	cin >> yl >> yt >> yw >> xb >> yb >> rad;
     
    	yw -= rad;
    	yl += rad;
     
    	ld xw = (yw - yl) * xb / (2 * yw - yl - yb);
     
    	if (dist(xw, yt) < rad) {
    		cout << - 1 << '\n';
    	}
    	else {
    		cout << fixed << setprecision(10);
    		cout << xw << endl;
    	}
     
    	return 0;
    }