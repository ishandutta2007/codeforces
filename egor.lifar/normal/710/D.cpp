#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>

using namespace std;


const long long mod = 1000000007;


long long gcd(long long a, long long b){
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a > b) {
        return gcd(b, a % b);
    } else {
        return gcd(a, b % a);
    }
}

long long gcd(long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; 
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


long long mymod(long long a, long long modulo) {
    long long x, y;
    gcd(a, modulo, x, y);
    return (x + modulo * modulo) % modulo;
}


int main() {
    long long a1, a2, b1, b2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
    long long d = gcd(a1, a2);
    if ((b1 - b2) % d != 0) {
        cout << 0 << endl;
        return 0;
    }
    long long x = (b1 % d + d) % d;
    b1 -= x;
    b2 -= x;
    l -= x;
    r -= x;
    if (b1 < 0) {
        b2 -= b1;
        l -= b1;
        r -= b1;
        b1 = 0;
    }
    if (b2 < 0) {
        b1 -= b2;
        l -= b2;
        r -= b2;
        b2 = 0;
    }
    if (r < 0) {
        cout << 0 << endl;
        return 0;
    }
    if (l < 0) {
        l = 0;
    }
    r -= r % d;
    if(l % d != 0) {
        l = l + d - l % d;
    }
    a1 /= d;
    a2 /= d;
    b1 /= d;
    b2 /= d;
    l /= d;
    r /= d;
    long long nlo1 = ((b2 - b1) % a2 + a2) % a2;
    long long k1 = (nlo1 * mymod(a1, a2)) % a2;
    long long nlo2 = ((b1 - b2) % a1 + a1) % a1;
    long long l1 = (nlo2 * mymod(a2, a1)) % a1;
    long long st = max(a1 * k1 + b1, a2 * l1 + b2);
    long long step = a1 * a2;
    if(st < l) {
        st += step * ((l - st) / step);
    }
    if (st < l) {
        st += step;
    }
    if (st < l) {
        st += step;
    }
    if (st > r) {
        cout << 0 << endl; 
        return 0;
    }
    cout << 1 + (r - st) / step << endl;
    return 0;
}