#include <bits/stdc++.h>

#define MOD 998244353
#define root 31
#define root_1 128805723
#define root_pw (1<<23)

using namespace std;
typedef long long ll;

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

int inv_mod(int x) { return expo(x, MOD - 2); }

int rev[2000002], a[2000002], b[2000002], tmp[2000002], sa, sb;

void NTT(int *a, int n, bool inverse) {
    for(int i = 1; i < n; ++i) {
        rev[i] = (rev[i>>1]>>1) | (i&1 ? n>>1 : 0);
        if (rev[i] < i) swap(a[i], a[rev[i]]);
    }

    for(int len = 2; len <= n; len <<= 1) {
		ll wlen = inverse ? root_1 : root;
		for(int i = len; i < root_pw; i <<= 1)
            wlen = wlen * wlen % MOD;

		for(int i = 0; i < n; i += len) {
			ll w = 1;
			for(int j = 0; j < len/2; ++j) {
				int u = a[i+j],  v = 1LL * a[i+j+len/2] * w % MOD;
				w = w * wlen % MOD;

				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				if(a[i+j] >= MOD) a[i+j] -= MOD;
				if(a[i+j+len/2] < 0) a[i+j+len/2] += MOD;
			}
		}
	}

    int revn =  inv_mod(n);
    for(int i = 0; inverse && i < n; ++i)
        a[i] = 1LL * a[i] * revn % MOD;
}

void multiply(int *a, int *b, int &sa, int sb) {
    int n = 1;
	while(n < sa + sb - 1) n <<= 1;

    NTT(a, n, false);

    memcpy(tmp, b, n * sizeof(int));
    NTT(tmp, n, false);

    for(int i = 0; i < n; i++)
        a[i] = 1LL * a[i] * tmp[i] % MOD;
    NTT(a, n, true);

    sa = n;
    while(sa > 0 && a[sa-1] == 0) sa--;
}

void square(int *a, int &sa) {
    int n = 1;
	while(n < 2*sa - 1) n <<= 1;

    NTT(a, n, false);
    for(int i = 0; i < n; i++)
        a[i] = 1LL * a[i] * a[i] % MOD;
    NTT(a, n, true);

    sa = n;
    while(sa > 0 && a[sa-1] == 0) sa--;
}


int n, k, x, ans;

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0; i < k; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    n /= 2, sa = 10, sb = 1, b[0] = 1;

    while(n) {
        if(n % 2 == 1) {
            multiply(b, a, sb, sa);
            n--;
        } else {
            square(a, sa);
            n /= 2;
        }
    }

    for(int i = 0; i < sb; i++) {
        ans = (ans + 1LL*b[i]*b[i]) % MOD;
    }

    printf("%d\n", ans);
    return 0;
}

// 204669874