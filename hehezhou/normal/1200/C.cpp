#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll n, m, g;
ll nn, mm;
int q;
int main() {
    ios :: sync_with_stdio(false);
    cin >> n >> m >> q;
    g = gcd(n, m);
    nn = n / g, mm = m / g;
    while(q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        b--;
        d--;
        ll la = a == 1 ? b / nn : b / mm, lb = c == 1 ? d / nn : d / mm;
        if(la == lb) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}