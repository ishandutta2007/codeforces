#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef complex<ld> Complex;
const ld PI = acos(-1.L);

// *** Fast Fourier Transform (Iterative) ***
// Reverse-bitmasking adder. rev_incr(a,n) returns REV(REV(a)+1)
inline int rev_incr(int a, int n) { int msk = n/2, cnt=0;
  while ( a&msk ) { cnt++; a<<=1; }
  a &= msk-1; a |= msk;
  while ( cnt-- ) a >>= 1;
  return a; }
// Compute in V the discrete fourier transform of v
// dir=1: forward transform, evaluates polynomial at complex roots of unity
// dir=-1: inverse transform, interpolates point-value form to coefficients
vector<Complex> FFT(const vector<Complex>& v, int dir=1) {
  Complex wm,w,u,t; int n = v.size(); vector<Complex> V(n);
  for (int k=0,a=0; k<n; ++k, a=rev_incr(a,n))
    V[a] = v[k] / ld(dir>0 ? 1 : n);
  for (int m=2; m<=n; m<<=1) {
    wm = polar( (ld)1, dir*2*PI/m );
    for (int k=0; k<n; k+=m) {
      w = 1;
      for (int j=0; j<m/2; ++j, w*=wm) {
        u = V[k + j];
        t = w * V[k + j + m/2];
        V[k + j] = u + t;
        V[k + j + m/2] = u - t;
      } } } return V; }

const int N = 1<<18;

ll nc2(int n) {
	return (ll)n*(n-1)/2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, x;
	cin >> n >> x;

	vector<int> diff;
	int in;
	int last = -1;
	for (int i=0; i<n; i++) {
		cin >> in;
		if (in < x) {
			diff.push_back(i-last);
			last = i;
		}
	}
	diff.push_back(n-last);

	vector<ll> ans(n+1,0);
	vector<Complex> a(2*N,0), b(2*N,0);
	int k = diff.size()-1;
	for (int i=0; i<=k; i++) {
		a[i] = b[k-i] = Complex(diff[i],0);
		ans[0] += nc2(diff[i]);
	}

	a = FFT(a);
	b = FFT(b);
	for (int i=0; i<2*N; i++) {
		a[i] *= b[i];
	}
	a = FFT(a,-1);

	for (int i=1; i<=k; i++) {
		ans[i] = llround(a[k-i].real());
	}

	for (int i=0; i<=n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}