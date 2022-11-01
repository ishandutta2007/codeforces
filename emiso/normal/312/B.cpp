#include <bits/stdc++.h>

using namespace std;

int main() {
	double a, b, c, d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf("%.9f\n", (a/b) / (1 - (1-a/b)*(1-c/d)));
	return 0;
}