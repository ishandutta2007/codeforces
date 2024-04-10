#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const long long mdl = 1000 * 1000 * 1000 + 7;

bool belongs(long long a, long long b, long long c, long long x) {
    if (x < a) {
        return false;
    }
    long long d = x - a;
    if (d % b != 0) {
        return false;
    }

    return d / b <= c - 1;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

vector <long long> getAllDivisors(long long x) {
    vector <long long> primes;
    vector <long long> powers;
    for (long long d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            primes.pb(d);
            long long p = 0;
            while (x % d == 0) {
                p++;
                x /= d;
            }
            powers.pb(p);  
        }
    }
    if (x > 1ll) {
        primes.pb(x);
        powers.pb(1ll);
    }

    vector <long long> divs;
    divs.pb(1ll);
    for (int i = 0; i < (int) primes.size(); i++) {
        int cursize = (int) divs.size();
        long long curval = primes[i];
        for (int j = 0; j < powers[i]; j++) {
            for (int k = 0; k < cursize; k++) {
                divs.pb(divs[k] * curval);
            }
            curval *= primes[i];
        }
    }

    return divs;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        long long b, q, y;
        long long c, r, z;
        cin >> b >> q >> y;
        cin >> c >> r >> z;

        if (!belongs(b, q, y, c) || !belongs(b, q, y, c + r * (z - 1)) || (r % q != 0ll)) {
            cout << 0 << endl;
            continue;
        }
        if (!belongs(b, q, y, c - r) || !belongs(b, q, y, c + r * z)) {
            cout << -1 << endl;
            continue;
        }

        vector <long long> divs = getAllDivisors(r);
        long long ans = 0;
        for (long long d : divs) {
            if (lcm(d, q) != r) {
                continue;
            }
            ans = (ans + r * r / (d * d)) % mdl;
        }
        cout << ans << endl;
    }

    return 0;
}