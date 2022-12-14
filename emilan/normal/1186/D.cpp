#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll M = 100000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) {
        double d;
        cin >> d;
        x = llround(M * d);
    }

    vector<bool> inte(n);
    for (int i = 0; i < n; i++) {
        a[i] += M * M;
        if (a[i] % M == 0) inte[i] = true;
        a[i] = a[i] / M - M;
    }

    ll sum = accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0; i < n; i++) {
        if (sum < 0 && !inte[i]) {
            a[i]++;
            sum++;
        }

        cout << a[i] << "\n";
    }
}