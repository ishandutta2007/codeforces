#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n;
int k;

bool query(ll L, ll R) {
    if (L > R) swap(L, R);
    L = max(L, 1LL);
    R = min(R, n);
    cout << L << " " << R << endl;
    string s;
    cin >> s;
    if (s == "Yes") {
        if (L == R)
            exit(0);
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);

    srand(time(nullptr));
    mt19937 gen(rand());
    cin >> n >> k;
    ll L = 1, R = n;
    while (true) {
        while (R - L > 40) {
            ll mid = (L + R) / 2;
            if (query(L, mid))
                R = mid;
            else
                L = mid + 1;
            L = max(1LL, L - k);
            R = min(n, R + k);
        }
        ll pos = uniform_int_distribution<ll>(L, R)(gen);
        query(pos, pos);
        L = max(1LL, L - k);
        R = min(n, R + k);
    }
}