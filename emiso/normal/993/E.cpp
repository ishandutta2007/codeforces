#include <bits/stdc++.h>
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef complex <double> base;

int rev(int k, int siz) {
    int sol = 0, log = log2(siz)-1;
    while (k) {
        if (k & 1)
            sol += 1 << log;
        k >>= 1;
        log--;
    }
    return sol;
}

void FFT(vector<base> &a, bool inverse) {
    int n = a.size();
    if(n == 1) return;

    for(int i=0; i<n; i++)
        if(i < rev(i, n))
            swap(a[i], a[rev(i,n)]);

    for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (inverse ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (inverse)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

vector<ll> multiply(vector<int> &a, vector<int> &b) {
    vector<base> fa(a.begin(), a.end()),fb(b.begin(), b.end());

    int n = 1;
    while(n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;

    fa.resize(n), fb.resize(n);

    FFT(fa, false);
    FFT(fb, false);
    for(int i=0; i<n; i++)
        fa[i] *= fb[i];
    FFT(fa, true);

    vector<ll> res(n);
    for(int i=0; i<n; i++)
        res[i] = ll(fa[i].real() + 0.5);

    return res;
}

int n, x, y, a[200020], acum;

int main() {
    scanf("%d %d", &n, &x);
    vector<int> l(n+1), r(n+1);

    for(int i = 0; i < n; i++) {
        scanf("%d", &y);
        a[i] = (y < x);
    }

    l[0]++; r[0]++;
    for(int i = 0; i < n; i++) {
        acum += a[i];
        l[acum]++;
    }
    acum = 0;
    for(int i = n-1; i >= 0; i--) {
        acum += a[i];
        r[acum]++;
    }

    vector<ll> c = multiply(l, r);
    ll z = c[acum] - n - 1;

    ll quant = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) quant++;
        if(a[i] == 1 || i + 1 == n) {
            z -= quant*(quant+1)/2;
            quant = 0;
        }
    }
    printf("%lld", z);
    for(int i = acum - 1; i >= 0; i--)
        printf("% lld", c[i]);
    for(int i = acum + 1; i <= n; i++)
        printf(" 0");
    puts("");

    return 0;
}