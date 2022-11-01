#include <bits/stdc++.h>

using namespace std;

double p, P[2020][2020];
int n, t;

void calc_P() {
	P[0][0] = 1;

	for(int t = 1; t < 2010; t++)
		for(int x = 0; x < 2010; x++)
			P[x][t] = ((x) ? (P[x-1][t-1] * p) : 0) + P[x][t-1] * ((x < n) ? (1 - p) : 1);
}

double EV(int t) {
	double ret = 0;
	for(int x = 1; x <= n; x++) {
		ret += (P[x][t] * x);
	}
	return ret;
}

int main() {
	cin >> n >> p >> t;

	calc_P();

	printf("%.9f\n", EV(t));
	return  0;
}

/*
P(x, t) = P(x-1, t-1) * p + P(x, t-1) * (1 - p)
EV(t) = sum from x = 1 to n P(x, t) * x / (n * (n + 1) / 2)


	for(int t = 1; t < 4; t++) {
		for(int x = 0; x < 4; x++)
			printf("%.4f ", P[x][t]);
		puts("");
	}
*/