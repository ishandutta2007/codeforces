#include <cstdio>

using namespace std;

const int N = 100010;

int n, q, flag;

int w[N];
int phi[100];

int calc_phi(int x);
int solve(int l, int r, int id);
int pow(int x, int k, int p);

int main() {
	scanf("%d%d", &n, &phi[0]);
	for (int i = 0; phi[i] != 1; ++i)
		phi[i + 1] = calc_phi(phi[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	scanf("%d", &q);
	while (q--) {
		int l, r;
		flag = 0;
		scanf("%d%d", &l, &r);
		printf("%d\n", solve(l, r, 0));
	}
	return 0;
}

int pow(int x, int k, int p) {
	int ret = 1;
	bool f = false;
	flag = 0;
	if (x >= p) {
		flag = 1;
		f = true;
	}
	x %= p;
	while (k) {
		if (k & 1) {
			if ((long long)ret * x >= p || f)
				flag = 1;
			ret = (long long)ret * x % p;
		}
		k >>= 1;
		if ((long long)x * x >= p)
			f = true;
		x = (long long)x * x % p;
	}
	return ret;
}

int solve(int l, int r, int id) {
	if (w[l] % phi[id] == 0) {
		flag = 1;
		return 0;
	}
	if (l == r) {
		if (w[l] >= phi[id])
			flag = 1;
		return w[l] % phi[id];
	}
	int q = solve(l + 1, r, id + 1);
	return pow(w[l], q + phi[id + 1] * flag, phi[id]);
}

int calc_phi(int x) {
	int ans = x, sie = x;
	for (int i = 2; i * i <= x; ++i)
		if (sie % i == 0) {
			ans = ans / i * (i - 1);
			while (sie % i == 0)
				sie /= i;
		}
	if (sie != 1)
		ans = ans / sie * (sie - 1);
	return ans;
}