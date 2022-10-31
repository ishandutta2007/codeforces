#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define SZ(x)(int((x).size()))
#define ALL(x)(x).begin(), (x).end()

template <typename T> inline bool chkmin(T & a,
    const T & b) {
    return b < a ? a = b, 1 : 0;
}
template <typename T> inline bool chkmax(T & a,
    const T & b) {
    return a < b ? a = b, 1 : 0;
}

typedef long long LL;

const LL infinity = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector <LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n != 1) {
        LL result = a.front() + a.back();
        for (int i = 0; i < n; i++) {
            if (i != 0 && i != n - 1) {
                if (a[i] > a[i - 1]) {
                    result += a[i] - a[i - 1];
                }
                if (a[i] > a[i + 1]) {
                    result += a[i] - a[i + 1];
                }
            } else if (i == 0 && a[0] > a[1]) {
                result += a[0] - a[1];
            } else if (i == n - 1 && a[n - 1] > a[n - 2]) {
                result += a[n - 1] - a[n - 2];
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != 0 && i != n - 1 && a[i] > max(a[i - 1], a[i + 1])) {
                result -= a[i] - max(a[i - 1], a[i + 1]);
                a[i] = max(a[i - 1], a[i + 1]);
            } else if (i == 0 && a[0] > a[1]) {
                result -= a[0] - a[1];
                a[0] = a[1];
            } else if (i == n - 1 && a[n - 1] > a[n - 2]) {
                result -= a[n - 1] - a[n - 2];
                a[n - 1] = a[n - 2];
            }
        }
        cout << result;
    } else {
        cout << a.front();
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}