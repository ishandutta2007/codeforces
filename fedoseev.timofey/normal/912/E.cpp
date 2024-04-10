#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 17;

vector <int> p;

vector <long long> A, B;

void go(int i, vector <int> &p, ll mx, ll cur, vector <ll> &out) {
    if (i == p.size()) {
        out.push_back(cur);
        return;
    }
    go(i + 1, p, mx, cur, out);
    while (mx / p[i] >= cur) {
        cur *= p[i];
        go(i + 1, p, mx, cur, out);
    }
}

ll get(ll x) {
    int j = 0;
    ll ans = 0;
    for (int i = 0; i < A.size(); ++i) {
        while (j < B.size() && B[j] <= x / A[i]) ++j;
        ans += j;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    ll k;
    cin >> k;
    vector <int> pA, pB;
    for (int i = 0; i < n; i += 2) pA.push_back(p[i]);
    for (int i = 1; i < n; i += 2) pB.push_back(p[i]);
    go(0, pA, (long long)1e18, 1, A);
    go(0, pB, (long long)1e18, 1, B);
    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll m = (r + l) >> 1;
        if (get(m) < k) l = m;
        else r = m;
    }
    cout << r << endl;
}