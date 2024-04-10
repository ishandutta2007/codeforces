#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MN 60006

const int SQMOD = (int)sqrt(MOD);
const double PI = acos((double)-1.0);

void addeq(int &a, int b) { a += b; if(a >= MOD) a -= MOD; }
int mul(int a, int b) { return (a * 1ll * b) % MOD; }

struct cplex {
	double x, y;
	cplex(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	inline cplex operator * (cplex b) { return cplex(x * b.x - y * b.y, x * b.y + y * b.x);}
	inline cplex operator + (cplex b) { return cplex(x + b.x, y + b.y); }
	inline cplex operator - (cplex b) { return cplex(x - b.x, y - b.y); }
	inline cplex conj() { return cplex(x, -y); }
	static cplex unitcircle (double x) { return cplex(cos(x), sin(x)); }
};

void fft(vector<cplex> &a) {
	int n = a.size();
	for(int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for(; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	vector<cplex> w(n / 2);
	w[0] = cplex(1);
	for(int len = 2; len <= n; len <<= 1) {
		for(int i = 1; i < len / 2; i++)
			w[i] = (i & (i - 1)) ? w[i & (i - 1)] * w[i & -i] : cplex::unitcircle(2 * i * PI / len);
		for(int i = 0; i < n; i += len) {
			for(int j = 0; j < len / 2; j++) {
				cplex u = a[i + j];
				cplex v = a[i + j + len / 2] * w[j];
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
			}
		}
	}
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
    if(a.size() * b.size() < 1000) {
        vector<int> c(a.size() + b.size());
        for(int i = 0; i < (int)a.size(); i++) {
            for(int j = 0; j < (int)b.size(); j++) {
                c[i+j] += 1LL * a[i] * b[j] % MOD;
                if(c[i+j] >= MOD) c[i+j] -= MOD;
            }
        }
        return c;
    }

	int n = 1;
	while(n < a.size() + b.size() - 1) n <<= 1;
	vector<cplex> fa(n, 0), fb(n, 0);
	for(int i = 0; i < a.size(); i++)
		fa[i] = cplex(a[i] / SQMOD, a[i] % SQMOD);
	for(int i = 0; i < b.size(); i++)
		fb[i] = cplex(b[i] / SQMOD, b[i] % SQMOD);
	fft(fa);
	fft(fb);
	vector<cplex> ia(n), ib(n);
	for(int i = 0; i < n; i++) {
		int j = (n - i) & (n - 1);
		cplex a1 = (fa[i] + fa[j].conj()) * cplex(0.5, 0);
		cplex a0 = (fa[i] - fa[j].conj()) * cplex(0, -0.5);
		cplex b1 = (fb[i] + fb[j].conj()) * cplex(0.5 / n, 0);
		cplex b0 = (fb[i] - fb[j].conj()) * cplex(0, -0.5 / n);
		ia[j] = a1 * b1 + a0 * b0 * cplex(0, 1);
		ib[j] = a1 * b0 + a0 * b1;
	}
	fft(ia);
	fft(ib);
	vector<int> c(a.size() + b.size() - 1, 0);
	for(int i = 0; i < c.size(); i++) {
		addeq(c[i], mul((long long)(ia[i].x + 0.5) % MOD, mul(SQMOD, SQMOD)));
		addeq(c[i], mul((long long)(ib[i].x + 0.5) % MOD, SQMOD));
		addeq(c[i], (long long)(ia[i].y + 0.5) % MOD);
	}
	return c;
}

typedef long long ll;

int k, fat[MN], invfat[MN], p2[MN];
ll n;

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) {
    return expo(a, MOD - 2);
}

void prep() {
    fat[0] = 1;
    for(ll i = 1; i < MN; i++)
        fat[i] = (i * fat[i-1]) % MOD;

    invfat[MN-1] = inv_mod(fat[MN-1]);
    for(ll i = MN-1; i > 0; i--)
        invfat[i-1] = (i * invfat[i]) % MOD;

    p2[0] = 1;
    for(int i = 1; i < MN; i++) {
        p2[i] = p2[i-1] * 2;
        if(p2[i] >= MOD) p2[i] -= MOD;
    }
}

vector<int> merge(vector<int> a, vector<int> b, int rsz) {
    if(a.empty()) return b;
    if(b.empty()) return a;

    int p2r = 1;
    for(int i = 0; i < (int)a.size(); i++) {
        a[i] = 1LL * a[i] * invfat[i] % MOD * p2r % MOD;
        p2r = 1LL * p2r * p2[rsz] % MOD;
    }
    for(int i = 0; i < (int)b.size(); i++) {
        b[i] = 1LL * b[i] * invfat[i] % MOD;
    }

    vector<int> c = multiply(a, b);
    c.resize(k + 1);
    for(int i = 0; i < (int)c.size(); i++) {
        c[i] = 1LL * fat[i] * c[i] % MOD;
    }

    return c;
}

int main() {
    scanf("%lld %d", &n, &k);

    if(n > k) {
        puts("0");
        return 0;
    }
    prep();

    vector<int> ans, base(k + 1, 1);
    base[0] = 0;

    for(int b = 0; b < 16; b++) {
        if(n & (1 << b)) ans = merge(ans, base, 1 << b);
        base = merge(base, base, 1 << b);
    }

    ll sum = 0;
    for(int i = 1; i <= k; i++) {
        sum = (sum + 1LL * ans[i] * fat[k] % MOD * invfat[i] % MOD * invfat[k-i] % MOD) % MOD;
    }

    printf("%lld\n", sum);
}