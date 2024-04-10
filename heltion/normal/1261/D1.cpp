#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353, G = 3;
constexpr int maxn = 1 << 20;
LL add(LL a, const LL& b){a += b; return a >= mod ? a - mod : a;}
LL sub(LL a, const LL& b){a -= b; return a < 0 ? a + mod : a;}
LL mul(const LL& a, const LL& b){return a * b % mod;}
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = mul(a, a)) if(r & 1) res = mul(res, a);
	return res;
}
void DFT(LL* a, int n, bool idft = false){
	static int r[maxn], on;
    static LL w[maxn], w_[maxn];
    if(on != n){
        r[1] = n >> 1; w[0] = w_[0] = 1; w[1] = power(G, (mod - 1) / n / 2); w_[1] = power(w[1], mod - 2);
        for(int i = 2; i < n; i += 1){  
            r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
            w[i] = mul(w[i - 1], w[1]);
            w_[i] = mul(w_[i - 1], w_[1]);
        }
        on = n;
    }
    for(int i = 0; i < n; i += 1) if(i < r[i]) swap(a[i], a[r[i]]);
	for(int m = 1; m <= n >> 1; m <<= 1)
		for(int j = 0; j < n; j += m << 1)
			for(int k = 0, p = 0; k < m; k += 1, p += n / m){
				LL tmp = mul(idft ? w_[p] : w[p], a[j + k + m]);
				a[j + k + m] = sub(a[j + k], tmp);
				a[j + k] = add(a[j + k], tmp);
			}
	if(idft) for(int i = 0, _ = power(n, mod - 2); i < n; i += 1) a[i] = mul(a[i], _);
}
int h[maxn];
LL a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    if(k == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i += 1) cin >> h[i];
    int m = 0;
    for(int i = 0; i < n; i += 1) if(h[i] != h[(i + 1) % n]) m += 1;
    a[0] = a[2] = 1;
    a[1] = (k - 2) % mod;
    DFT(a, maxn);
    for(int i = 0; i < maxn; i += 1) a[i] = power(a[i], m);
    DFT(a, maxn, true);
    LL ans = 0;
    for(int i = m + 1; i <= 2 * m; i += 1) ans = add(ans, a[i]);
    cout << ans * power(k, n - m) % mod;
    return 0;
}

//(x^(-1)+x+(k-2))^m k^(n-m)