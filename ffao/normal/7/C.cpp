#include <stdio.h>
#include <iostream>

using namespace std;

long long a, b, c;

struct bezout { long long d,a,b;};
bezout extgcd(long long x, long long y) {
    if (y == 0) return (bezout){x,1,0};
    bezout s = extgcd(y, x%y);
    return (bezout){s.d, s.b, s.a-x/y*s.b};
}

const long long lim = 5000000000000000000LL;

int main() {
    cin >> a >> b >> c;
    
    bezout resp = extgcd(a, b);
    if (c % resp.d != 0) {
        printf("-1\n");
        return 0;
    }
    
    resp.a *= -c/resp.d;
    resp.b *= -c/resp.d;
    if (resp.a < -lim || resp.a > lim || resp.b < -lim || resp.b > lim) {
        printf("-1\n");
        return 0;
    }
    cout << resp.a << " " << resp.b << endl;
}