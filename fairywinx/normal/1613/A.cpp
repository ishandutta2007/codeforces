#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    long long a1, cnt1;
    cin >> a1 >> cnt1;
    long long  a2, cnt2;
    cin >> a2 >> cnt2;
    if (a1 == 0 || a2 == 0) {
        if (a1 == a2) {
            cout << "=\n";
        } else if (a1 < a2) {
            cout << "<\n";
        } else {
            cout << ">\n";
        }
        return;
    }
    while (a1 % 10 == 0) {
        ++cnt1;
        a1 /= 10;
    }
    while (a2 % 10 == 0) {
        ++cnt2;
        a2 /= 10;
    }
    if (a1 == a2 && cnt1 == cnt2) {
        cout << "=\n";
        return;
    }
    int c = min(cnt1, cnt2);
    cnt1 -= c, cnt2 -= c;
    if (max(cnt1, cnt2) > 9) {
        if (cnt1 > cnt2) {
            cout << ">\n";
        } else {
            cout << "<\n";
        }
        return;
    }
    while (cnt1) {
        --cnt1;
        a1 *= 10;
    }
    while (cnt2) {
        --cnt2;
        a2 *= 10;
    }
    if (a1 > a2) {
        cout << ">\n";
    } else {
        cout << "<\n";
    }
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}