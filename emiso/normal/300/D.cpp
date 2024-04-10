#include <bits/stdc++.h>
#define PI acos(-1)
#define MOD 7340033
#define root 5          
#define root_1 4404020  
#define root_pw (1<<20) 

using namespace std;
typedef long long ll;

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

ll pow_mod(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    for(;b > 0; b >>= 1){
        if(b % 2) ret = (ret * a) % MOD;
        a = (a*a) % MOD;
    }
    return ret;
}

void FFT(vector<ll> &a, bool inverse) {
    int n = a.size();
    if(n == 1) return;

    for(int i=0; i<n; i++)
        if(i < rev(i, n))
            swap(a[i], a[rev(i,n)]);

    for (int len=2; len<=n; len<<=1) {
		ll wlen = inverse ? root_1 : root;
		for(int i = len; i < root_pw; i <<= 1) {
            wlen = (wlen * wlen) % MOD;
		}

		for (int i=0; i<n; i+=len) {
			ll w = 1;
			for (int j=0; j<len/2; ++j) {
				ll u = a[i+j],  v = (a[i+j+len/2] * w) % MOD;
				a[i+j] = (u + v) % MOD;
				a[i+j+len/2] = (u - v + MOD) % MOD;
				w = (w * wlen) % MOD;
			}
		}
	}
	if (inverse) {
        ll revn = pow_mod(n, MOD - 2);
		for (int i=0; i<n; ++i)
			a[i] = (a[i] * revn) % MOD;
	}
}

vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
    vector<ll> fa(a.begin(), a.end()),fb(b.begin(), b.end());

    int n = 1;
    while(n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;

    fa.resize(n), fb.resize(n);

    FFT(fa, false);
    FFT(fb, false);
    for(int i=0; i<n; i++)
        fa[i] *= fb[i];
    FFT(fa, true);

    vector<ll> res(min(n, 1000));
    for(int i=0; i<min(n ,1000); i++)
        res[i] = fa[i] % MOD;

    return res;
}

vector<ll> dp[33];
int t, N, k;

vector<ll> solve(int n) {
    vector<ll> ret;
    if(n == 0) {
        ret.push_back(1);
        return dp[n] = ret;
    }

    ret = solve(n - 1);
    ret = multiply(ret, ret);
    ret = multiply(ret, ret);
    ret.insert(ret.begin(), 1);
    return dp[n] = ret;
}

int SHAZAM(int n) {
    int ans = 0;
    while(n != 1 && n % 2 > 0) {
        ans++;
        n /= 2;
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    solve(32);
    while(t--) {
        scanf("%d %d", &N, &k);
        int idx = SHAZAM(N);
        printf("%lld\n", (k < dp[idx].size()) ? dp[idx][k] : 0);
    }
    return 0;
}