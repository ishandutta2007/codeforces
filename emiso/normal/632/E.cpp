#include <bits/stdc++.h>
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef complex <double> base;

int n;

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

vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());

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
    int last = 0;
    for(int i=0; i<n; i++) {
        res[i] = ll(fa[i].real() + 0.5);
        if(res[i] != 0) {
            res[i] = 1;
            last = i;
        }
    }
    res.resize(last + 1);

    return res;
}

vector<ll> fast_fftation(vector<ll> &a, int expo) {
    if(expo == 1) return a;
    vector<ll> b = fast_fftation(a, expo / 2), c = multiply(b, b);
    if(expo % 2) return multiply(a, c);
    return c;
}

int k, x;
vector<ll> A(1001, 0);

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
       scanf("%d", &x);
       A[x] = 1;
    }

    vector<ll> ans = fast_fftation(A, k);

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] != 0) printf("%d ", i);
    }
    //cerr << endl << ans.size() << endl << endl;
    return 0;
}