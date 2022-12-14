#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

using ll = long long;
#define debug(x) cerr << #x << ": <" << x << ">\n"
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ioThings();

    int n; cin >> n;
    int a[n], bits[31] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 31; j++)
            bits[j] += (a[i] >> j) & 1;
    }
    int neg = 0;
    for (int i = 0; i < 31; i++) {
        debug(bits[i]);
        if (bits[i] > 1)
            neg |= 1 << i;
    }
    int max = 0;
    for (int i = 1; i < n; i++) {
        if ((a[i] & ~neg) > (a[max] & ~neg))
            max = i;
    }
    if (max)
        swap(a[0], a[max]);
    for (int i = 0; i < n; i++) {
        if (i)
            cout << ' ';
        cout << a[i];
    }

    return 0;
}