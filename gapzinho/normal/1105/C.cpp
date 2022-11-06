#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1005;
const ll mod = 1e9+7;

ll v[ms];
ll temp[ms];

ll get(ll x, int willBe, int isNow) {
    int y = (willBe - isNow);
    if(y < 0) y += 3;
    return (x+3-y)/3;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie();
    ll n, l, r;
    cin >> n >> l >> r;
    v[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int a = 0; a < 3; a++) {
            temp[a] = 0;
            for(int b = 0; b < 3; b++) {
                temp[a] = (temp[a] + v[b] * (get(r, a, b) - get(l-1, a, b))) % mod;
            }
        }
        swap(v, temp);
    }
    cout << v[0] << endl;
}