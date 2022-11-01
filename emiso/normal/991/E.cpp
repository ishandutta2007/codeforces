#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll freq[10], f_[10], fat[20];
ll n, sz;

ll arranjo() {
    ll ret = fat[sz];
    for(int d = 0; d <= 9; d++)
        ret /= fat[f_[d]];
    return ret;
}

ll solve(ll d) {
    if(d == 10) {
        ll ret = arranjo();

        if(f_[0] > 0) {
            ll leading0 = 1;
            f_[0]--; sz--;
            leading0 *= arranjo();
            f_[0]++; sz++;
            ret -= leading0;
        }

        return ret;
    } else {
        ll res = 0;
        if(freq[d] == 0) {
            f_[d] = 0;
            res = solve(d + 1);
        } else {
            for(int F = 1; F <= freq[d]; F++) {
                sz -= f_[d];
                f_[d] = F;
                sz += f_[d];

                res += solve(d + 1);
            }
        }
        return res;
    }
}

int main() {
	scanf("%lld", &n);

	fat[0] = 1;
	for(ll i = 1; i < 20; i++) {
		fat[i] = fat[i-1] * i;
	}

	for(ll N = n; N; N /= 10) {
        freq[N % 10]++;
	}

	printf("%lld\n", solve(0));
	return 0;
}