#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
double P;

int main() {
	scanf("%d%lf", &N, &P);
	int l = -1, r = N - 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		double gal = (.5 * m * (N - m) * (N - m - 1) / 2 + m * (m - 1) / 2 * (N - m) + m * (m - 1) * (m - 2) / 6) / (N * (N - 1) * (N - 2) / 6);
		if (gal >= P - 1e-8) r = m;
		else l = m;
	}
	printf("%d\n", r);
	return 0;
}