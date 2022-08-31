#include <cstdio>

#include <algorithm>
#include <complex>

typedef std::complex<double> complex;

const int LGN = 19, N = 1 << LGN;

int n;
int cnt[N];

int rev[N];
complex a[N], b[N], c[N];

void fft(complex* a, int lgn, int d);

int main() {
	int x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		cnt[i] = (a < x) + cnt[i - 1];
	}
	for (int i = 0; i <= n; ++i)
		a[cnt[i]] = a[cnt[i]] + complex(1);
	for (int i = 0; i <= n; ++i)
		b[n - i] = a[i];

	int lgn = 0;

	while ((1 << lgn) <= n * 2)
		++lgn;
	int upn = 1 << lgn;
	for (int i = 1; i < upn; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lgn - 1));

	long long del = 0;
	for (int i = 0; i <= n; ++i)
		del += (long long) round(a[i].real() * (a[i].real() + 1) / 2);

	fft(a, lgn, 1);
	fft(b, lgn, 1);
	for (int i = 0; i < (1 << lgn); ++i)
		c[i] = a[i] * b[i];
	fft(c, lgn, -1);
	for (int i = 0; i < (1 << lgn); ++i)
		c[i] /= (1 << lgn);

	printf("%I64d", (long long) round(c[n].real()) - del);
	for (int i = n + 1; i <= n * 2; ++i)
		printf(" %lld", (long long) round(c[i].real()));

	return 0;
}

void fft(complex* a, int lgn, int d) {
	int n = 1 << lgn;
	for (int i = 0; i < n; ++i)
		if (i < rev[i])
			swap(a[i], a[rev[i]]);
	for (int i = 0; i < lgn; ++i) {
		int t = 1 << i;
		complex w1(cos(M_PI / t), sin(M_PI / t) * d);
		for (int j = 0; j < n; j += t << 1) {
			complex w(1, 0);
			complex* p = a + j;
			for (int k = 0; k < t; ++k) {
				complex x = p[k + t] * w;
				p[k + t] = p[k] - x;
				p[k] += x;
				w *= w1;
			}
		}
	}
}