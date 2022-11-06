#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <complex>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

typedef complex<double> point;

const double E = 1e-9;
bool eq(double a, double b) {return fabs(a-b) < E;}

int main(int argc, char ** argv)
{
	int a, b;

	scanf("%d %d", &a, &b);

	int y0 = 0, x0 = 0;
	for (int y1 = -a; y1 <= a; y1++) {
		int absx1 = round(sqrt(a*a - y1*y1));
		if (absx1*absx1 + y1*y1 != a*a) continue;
		for (int m = -1; m <= 1; m += 2) {
			int x1 = m * absx1;
			
			point p0(x0, y0);
			point p1(x1, y1);

			for (int m2 = -1; m2 <= 1; m2 += 2) {
				point diff = p1 - p0;
				diff /= abs(diff);
				diff *= point(0, m2);
				diff *= b;
				point p2 = p0 + diff;

				bool fail = false;
				point ps[3] = {p0, p1, p2};
				for (int i = 0; i < 3; i++) {
					if (!eq(real(ps[i]), round(real(ps[i])))) fail = true;
					if (!eq(imag(ps[i]), round(imag(ps[i])))) fail = true;
					for (int j = i+1; j < 3; j++)
						if (eq(real(ps[i]), real(ps[j])) || eq(imag(ps[i]), imag(ps[j])))
							fail = true;
				}

				if (!fail) {
					printf("YES\n");
					for (int i = 0; i < 3; i++)
						printf("%d %d\n", (int)round(real(ps[i])), (int)round(imag(ps[i])));
					return 0;
				}
			}
		}
	}

	printf("NO\n");

	return 0;
}