#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int md = 1e9 + 7;

map <int, int> t;

typedef long long ll;


ll binpow(ll a, ll n) {
    if (n == 0) return 1;
    else if (n % 2 == 0) {
        ll t = binpow(a, n / 2) % md;
        return t * t % md;
    }
    else
        return a * binpow(a, n - 1) % md;
}

void fact(int n, vector <int> &f) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            f.push_back(i);
            if (i * i < n) f.push_back(n / i);
        }
    }
}

int calc(int n) {
    if (!t.count(n)) {
        vector <int> k;
        fact(n, k);
        ll res = binpow(2, n - 1);
        for (int i = 1; i < k.size(); ++i) {
            res -= calc(n / k[i]);
            if (res < 0) res += md;
            if (res >= md) res -= md;
        }
        t[n] = res;
    }
    return t[n];
}

int main() {
    int x, y;
    cin >> x >> y;
    if (y % x) {
        cout << 0 << endl;
        return 0;
    }
    y /= x;
    cout << calc(y) << endl;
}