#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> ans;
map<ll, vector<ll>> divi;

#define LIM 100000

void solve(ll x, ll k) {
    if(ans.size() >= LIM) return;
    if(x == 1 || k == 0) ans.push_back(x);
    else {
        vector<ll> &ds = divi[x];
        for(ll &d : ds) solve(d, k-1);
    }
}

int main() {
    ll x, k;
    scanf("%lld %lld", &x, &k);

    vector<ll> dx;
    for(ll d = 1; d * d <= x; d++) {
        if(x % d == 0) {
            dx.push_back(d);
            if(d * d < x) dx.push_back(x / d);
        }
    }
    sort(dx.begin(), dx.end());

    for(ll d : dx)
        for(ll m : dx)
            if(m % d == 0)
                divi[m].push_back(d);

    solve(x, k);
    for(int i = 0; i < min(LIM, (int)ans.size()); i++)
        printf("%lld ", ans[i]);

    return 0;
}
//1000000000000 1000000000000000000
//963761198400 1000000000000000000