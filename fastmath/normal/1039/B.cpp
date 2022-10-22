#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;
const int KEK = 100;

bool dbg = 0;

mt19937 rnd(228);

int rnd_() {
    int ans = ((long long)rnd() << 32) + rnd();
    return abs(ans);
}

int test = 0;
int n, k;
int quer = 0;
int curr = -1;

const int K = 4500;

bool get(int l, int r) {    
    if (dbg) {
        ++quer;

        if (quer > K) {
            cout << "LOSE\n";
            cout << test << '\n';
            exit(0);
        }

        bool ans = (l <= curr && curr <= r);
        if (ans && l == r) {
            cout << "WIN\n";
            cout << quer << "\n\n";
        }

        if (k) {
            int tl = max(1ll, l - k);
            int tr = min(n, r + k);
            curr = tl + rnd_() % (tr - tl);
        }

        return ans;
    }
    else {
        cout << l << ' ' << r << '\n';
        fflush(stdout);

        string ans;
        cin >> ans;
        fflush(stdout);

        if (l == r && ans == "Yes") exit(0);
        return (ans == "Yes");
    }
}

signed main() {

    while (1) {
    quer = 0;

    if (dbg) {
        n = rnd_() % INF + 1;
        k = rnd_() % 10 + 1;
        curr = rnd_() % n + 1;
        cout << "test " << n << ' ' << k << '\n';
    }
    else {
        cin >> n >> k;
    }

    int l = 1;
    int r = n;
    while (1) {
        if (r - l < KEK) {
            int len = r - l + 1;
            int p = l + rnd() % len;
            if (get(p, p)) break;
        }
        else {
            int m = (l + r) / 2;
            if (get(l, m)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }

        l = max(1ll, l - k);
        r = min(n, r + k);
    }
    ++test;
    }

    return 0;
}