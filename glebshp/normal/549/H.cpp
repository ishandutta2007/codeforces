#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

long double ans = 1e18;
long double eps = 1e-12;

long long sgn[4];

void solve_eq(long long a, long long b, long long c) {
    if (a != 0)
    	return;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				ans = min(ans, (long double) 0.0);
			}
		} else {
			ans = min(ans, fabs(-((long double) c) / b));
		}
	} else {
		long long d = b * b - 4 * a * c;
//				cerr << a << ' ' << b << ' ' << c << ' ' << d << endl;

		if (d >= 0) {
			long double sq = sqrt((long double) d);
			ans = min(ans, fabs(((long double)-b + sq)	/ (2 * a)));
			ans = min(ans, fabs(((long double)-b - sq) / (2 * a)));
		}
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cout.precision(20);

   	long long a, b, c, d;
   	cin >> a >> b >> c >> d;
   	if ((a * d - b * c) == 0ll) {
   		cout << 0 << endl;
   	} else {
   		ans = (long double) max(max(abs(a), abs(b)), max(abs(c), abs(d)));
   		for (int msk = 0; msk < 16; msk++) {
   			long long h = msk;
   			for (int i = 0; i < 4; i++) {
   				sgn[i] = (h % 2) * 2 - 1;
   				h /= 2;
   			}

   			solve_eq(sgn[0] * sgn[3] - sgn[1] * sgn[2], sgn[0] * d + sgn[3] * a - (sgn[1] * c + sgn[2] * b), a * d - b * c);
   		}

   		cout << ans << endl;
   	}

    return 0;
}