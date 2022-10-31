#include <bits/stdc++.h>
#define MN 10000010

using namespace std;
typedef long long ll;

vector <bool> isp(MN, 1);
vector <int> primes, phi(MN), filhos[MN];
int n;
ll acum[MN];

void sieve() {
    isp[0] = isp[1] = 0;
    phi[1] = 1;

    for(int i = 2; i < MN; i++) {
        if(isp[i]) {
            if(i <= n) filhos[primes.size()].push_back(i);
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for(int j = 0; j < primes.size() && i * primes[j] < MN; j++) {
            int pj = primes[j];
            isp[i * pj] = 0;
            if(i * pj <= n) filhos[j].push_back(i * pj);

            if(i % pj == 0) {
                phi[i * pj] = phi[i] * pj;
                break;
            }
            else {
                phi[i * pj] = phi[i] * phi[pj];
            }
        }
    }

    for(int i = 0; i < MN; i++) {
        acum[i] = filhos[i].size();
        if(i) acum[i] += acum[i-1];
    }
}

int main() {
    scanf("%d", &n);
    sieve();

    ll ans = 0;
    for(int i = 2; i <= n; i++) {
        ans += 2 * (phi[i] - 1);
        ans += (i - phi[i] - 1);
    }

    int tn = n - 2, last = primes.size() - 1;
    for(int i = primes.size() - 1; i >= 0; i--, last--) {
        int pi = primes[i];
        if(2 * pi <= n) break;
        if(pi <= n) ans -= 2*(tn--);
    }

    for(int l = 1; l < primes.size(); l++) {
        ll pl = primes[l];
        if(2 * pl > n) break;

        int lb = l + 1, rb = primes.size() - 1;
        while(lb < rb) {
            int mb = (lb + rb) / 2;
            ll pm = primes[mb];

            if(pl * pm > n) rb = mb;
            else lb = mb + 1;
        }

        int r = lb;
        ans += (1LL * filhos[l].size() * (acum[last] - acum[r-1]));
    }

    printf("%lld\n", ans);

    return 0;
}