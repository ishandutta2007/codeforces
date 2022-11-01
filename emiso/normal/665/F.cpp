#include <bits/stdc++.h>
#define MN 2000100

using namespace std;
typedef long long ll;

vector<int> isp(MN);
vector<ll> primes, acum_pi(MN);

int phi_table[300000][100];

void crivo_super_modificado_3000_v2_beta() {
	for(int i=2; i<MN; i++) isp[i] = 1;
	for(int i=2; i<MN; i++) {
		if(isp[i]) {
            primes.push_back(i);
			for(int j=2*i; j<MN; j+=i)
				isp[j] = 0;
		}
        acum_pi[i] = acum_pi[i-1] + isp[i];
    }

    for(int i=0; i<300000; i++) {
        phi_table[i][0] = i;
        for(int k=1; k<100; k++) {
            phi_table[i][k] = phi_table[i][k-1] - phi_table[i/primes[k-1]][k-1];
        }
    }

}

///Phi function
ll solve(ll n, ll k) {
    if(n < 300000 && k < 100) return phi_table[n][k];
    if(k == 0) return n;
    if(n < primes[k - 1] * primes[k - 1]) return acum_pi[n] - k + 1;
    return solve(n, k - 1) - solve(n/primes[k - 1], k - 1);
}

///Prime count up to X
ll pi_(ll x) {
    if(x < MN) return acum_pi[x];
    ll cubic_root = ceil(pow(x, 1.0/3));

    ll k = acum_pi[cubic_root];

    ll ret = solve(x, k) + k - 1;
    while(primes[k] * primes[k] <= x) {
        ret = ret - pi_(x / primes[k]) + k;
        k++;
    }
    return ret;
}

ll n, ans;

int main() {
	crivo_super_modificado_3000_v2_beta();

	scanf("%lld", &n);

    for(int i = 0; i < primes.size(); i++) {
        ll pi = primes[i];
        if(pi >= n / pi) break;

        if(pi * pi * pi <= n) ans++;
        ans += pi_(n / pi) - i - 1;
    }

	printf("%lld\n", ans);
	return 0;
}