#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
double answer;
void rec(double p, double a, double b, double c, double v) {
	answer += p;
	if(a > eps) {
		double take = min(a, v);
		rec(p * a, a - take, (b > eps ? b + take / 2 : 0), c + take / 2, v);
	}
	if(b > eps) {
		double take = min(b, v);
		rec(p * b, (a > eps ? a + take / 2 : 0), b - take, c + take / 2, v);
	}
}

void test_case() {
	double a, b, c, v;
	cin >> a >> b >> c >> v;
	rec(1.0, a, b, c, v);
	printf("%.10lf\n", answer);
	answer = 0;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
}