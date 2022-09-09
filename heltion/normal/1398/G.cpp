#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1 << 20;
const double PI = acos(-1);
struct comp{
	double a, b;
	comp(double a = 0, double b = 0) : a(a), b(b){};
	comp operator + (const comp& x)const{return comp(a + x.a, b + x.b);}
	comp operator - (const comp& x)const{return comp(a - x.a, b - x.b);}
	comp operator * (const comp& x)const{return comp(a * x.a - b * x.b, a * x.b + b * x.a);}
	comp operator / (const int& x)const{return comp(a / x, b / x);}
	comp conj()const{return comp(a, -b);}
};
void FFT(comp* a, int n, bool inv = false){
	static int on = 0, rev[maxn];
	static comp w[maxn];
	if(on != n){
		for(int i = 0; i < n; i += 1){
			rev[i] = i ? rev[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0) : 0;
			w[i] = comp(cos(PI / n * i), sin(PI / n * i));
		}
		on = n;
	}
	for(int i = 0; i < n; i += 1) if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int m = 1; m <= n >> 1; m <<= 1)
		for(int j = 0; j < n; j += m << 1)
			for(int k = 0, p = 0; k < m; k += 1, p += n / m){
				comp tmp = (inv ? w[p].conj() : w[p]) * a[j + k + m];
				a[j + k + m] = a[j + k] - tmp;
				a[j + k] = a[j + k] + tmp;
			}
	if(inv) for(int i = 0; i < n; i += 1) a[i] = a[i] / n;
}
void multiply(LL *f, LL *g, LL *h, int n){
	static comp a[maxn], b[maxn];
	for(int i = 0; i < n; i += 1) a[i] = comp(f[i], g[i]);
	FFT(a, n);
	for(int i = 0, j = 0; i < n; i += 1, j = (n - i) & (n - 1))
		b[i] = (a[i] * a[i] -  (a[j] * a[j]).conj()) * comp(0, -.25);
	FFT(b, n, true);
	for(int i = 0; i < n; i += 1) h[i] = b[i].a + .5;
}
LL f[maxn], g[maxn], h[maxn];
int ans[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 0, a; i <= n; i += 1){
        cin >> a;
        f[a] += 1;
        g[x - a] += 1;
    }
    multiply(f, g, h, maxn);
    fill(ans, ans + maxn + 1, -1);
    for(int i = 1; i <= x; i += 1) if(h[i + x]){
        int d = 2 * (i + y);
        for(int j = d; j <= maxn; j += d) ans[j] = d;
    }
    int q, l;
    for(cin >> q; q; q -= 1){
        cin >> l;
        cout << ans[l] << " ";
    }
    return 0;
}