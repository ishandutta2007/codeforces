#include <bits/stdc++.h>
using namespace std;

typedef complex<double> Complex;
typedef long double ld;
typedef long long ll;

const int ms = 2e6+5;
const ld pi = acosl(-1.0);

int rbit[1 << 23];
Complex a[ms], b[ms];

void calcReversedBits(int n) {
    int lg = 0;
    while(1 << (lg + 1) < n) {
        lg++;
    }
    for(int i = 1; i < n; i++) {
        rbit[i] = (rbit[i >> 1] >> 1) | ((i & 1) << lg);
    }
}

void fft(Complex a[], int n, bool inv = false) {
    for(int i = 0; i < n; i++) {
        if(rbit[i] > i) swap(a[i], a[rbit[i]]);
    }
		
    double ang = inv ? -pi : pi;
    for(int m = 1; m < n; m += m) {
        Complex d(cosl(ang/m), sinl(ang/m));
        for(int i = 0; i < n; i += m+m) {
            Complex cur = 1;
            for(int j = 0; j < m; j++) {
                Complex u = a[i + j], v = a[i + j + m] * cur;
                a[i + j] = u + v;
                a[i + j + m] = u - v;
                cur *= d;
            }
        }
    }
    if(inv) {
        for(int i = 0; i < n; i++) a[i] /= n;
    }
}

void multiply(ll x[], ll y[], ll ans[], int nx, int ny, int &n) {
    n = 1;
    while(n < nx+ny) n <<= 1; 
    /*cout << "Multiplicandoo: " << endl;
    for(int i = 0; i < n; i++) cout << x[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) cout << y[i] << ' ';
    cout << '\n';*/
    calcReversedBits(n);
    for(int i = 0; i < n; i++) {
        a[i] = Complex(x[i]);
        b[i] = Complex(y[i]);
    }
    fft(a, n); fft(b, n);
    for(int i = 0; i < n; i++) {
        a[i] = a[i] * b[i];
    }
    fft(a, n, true);
    for(int i = 0; i < n; i++) {
        ans[i] = ll(a[i].real() + 0.5);
        ans[i] = !!ans[i];
    }
    /*cout << "=\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n\n";*/
    //n = nx + ny;
}

ll ans[ms], x[ms];

int fExp(int b, int nx) {
    ans[0] = 1;
    int n = 1;
    //cout << "FFT feito" << endl;
    while(b) {
        if(b&1) multiply(ans, x, ans, n, nx, n);
        multiply(x, x, x, nx, nx, nx);
        b >>= 1;
    }
    return n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(1);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		x[k] = 1;
	}
	int ansSz = fExp(k, 1000);
	for(int i = 0; i < ansSz; i++) {
		/*if(abs(ans[i]) > eps) {
			cout << i << ' ';
		}*/
		if(ans[i] > 0) cout << i << ' ';
	}
	cout << endl;
	return 0;
}