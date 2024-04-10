#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll egcd (ll a, ll b, ll &x, ll &y) {
    if (b==0) { x=1, y=0; return a; }
    ll p=egcd(b, a%b, x, y);
    ll t=x; x=y; y=t-(a/b)*x;
    return p;
}

int main()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c;
    ll gcd = egcd(a, b, x, y);
    if (c%gcd) cout << -1;
    else cout << x*(-c)/gcd << ' ' << y*(-c)/gcd;
    return 0;
}