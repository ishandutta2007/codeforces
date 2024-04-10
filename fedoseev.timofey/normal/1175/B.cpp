#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Inf = 4294967296;

ll mul(ll a, ll b) {
    ll x = a * b;
    if (x > Inf) return Inf;
    return x;
}

void add(ll &a, ll b) {
    a += b;
    if (a > Inf) a = Inf;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int l;
    cin >> l;
    ll ans = 0;
    vector <ll> res;
    res.push_back(1);
    for (int i = 0; i < l; ++i) {
        string s;
        cin >> s;
        if (s == "end") {
            res.pop_back();
        }
        else if (s == "for") {
            int x;
            cin >> x;  
            res.push_back(mul(res.back(), x));
        }
        else {
            add(ans, res.back());
        }
    }
    if (ans == Inf) {
        cout << "OVERFLOW!!!" << '\n';
    }
    else {
        cout << ans << '\n';
    }
}