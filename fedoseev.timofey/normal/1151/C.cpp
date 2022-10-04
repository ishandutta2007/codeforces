#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

void mod(int &x) {
    x = ((x % md) + md) % md;
}

int get(ll r) {
    ll tk = 0;
    ll cnt = 1;
    int sum = 0;

    int id = 0;
    ll fir = 1;
    ll sec = 2;

    while (tk < r) {
        int cur = min(cnt, r - tk);
        int tmp = cur;
        mod(cur);
        if (id == 0) {
            sum += (fir + (cur - 1)) * cur;
            fir += 2 * tmp;
        }
        else {
            sum += (sec + (cur - 1)) * cur;
            sec += 2 * tmp;
        }
        mod(sum);
        mod(fir);
        mod(sec);
        cnt *= 2;
        id ^= 1;
        tk += tmp;
    }
    return sum;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll l, r;
    cin >> l >> r;
    cout << ((get(r) - get(l - 1)) % md + md) % md << '\n';
}