#include<cstdio>
int n, m;
int a[1010][1010];
long long int sumpos[1010];
long long int sumsqpos[1010];
long long int basesump;
long long int accsump;
long long int bsqp;
long long int vsqp;
long long int rsqp;
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		sumpos[i] = 0;
		sumsqpos[i] = 0;
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			sumpos[i] += a[i][j];
			sumsqpos[i] += 1LL * a[i][j] * a[i][j];
		}
	}
	if (sumpos[1] * 2 == sumpos[0] + sumpos[2]) {
		accsump = sumpos[1] - sumpos[0];
		basesump = sumpos[0];
		bsqp = sumsqpos[0];
		vsqp = sumsqpos[1] - sumsqpos[0];
		rsqp = sumsqpos[2] - sumsqpos[1] - vsqp;
	}
	else {
		accsump = sumpos[4] - sumpos[3];
		basesump = sumpos[3] - accsump * 3;
		vsqp = sumsqpos[4] - sumsqpos[3];
		rsqp = sumsqpos[5] - sumsqpos[4] - vsqp;
		vsqp -= 3 * rsqp;
		bsqp = sumsqpos[3] - 3 * vsqp - 3 * rsqp;
	}
	int ansy = 0;
	long long int csqp = bsqp;
	long long int cvsqp = vsqp;
	for (int i = 0; i < n; i++) {
		if (sumpos[i] != basesump + i * accsump) {
			long long int posdiff = basesump + i * accsump - sumpos[i];
			long long int sqposdiff = csqp - sumsqpos[i];
			long long int recpos = (sqposdiff + posdiff * posdiff) / (2 * posdiff);
			printf("%d %lld\n", i, recpos);
			break;
		}
		csqp += cvsqp;
		cvsqp += rsqp;
	}
	fflush(stdout);
	return 0;
}