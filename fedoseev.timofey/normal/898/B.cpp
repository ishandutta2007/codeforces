#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

long long n, a, b;

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll gcd(ll a, ll b) {
    while (b) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void change(ll &c, ll &d) {
    ll k = (-c + b - 1) / b;
    c += k * b;
    d -= k * a;
}

int main() {
    cin >> n >> a >> b;
    ll g = gcd(a, b);
    if (n % g) {
        cout << "NO" << endl;
    }
    else {
        ll k = n / g;
        ll c = 0;
        ll d = 0;
        gcd(a, b, c, d);
        c *= k;
        d *= k;
        if (c < 0) change(c, d);
        else if (d < 0) {
            swap(c, d);
            swap(a, b);
            change(c, d);
            swap(c, d);
        }
        if (c >= 0 && d >= 0) {
        cout << "YES" << endl;
        cout << c << " " << d << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}