#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    vt<int> a_left, a_right, b(k);
    while (n--) {
        int x;
        cin >> x;
        if (x <= p) a_left.push_back(x);
        else a_right.push_back(x);
    }
    for (int &i : b) cin >> i;

    sort(all(a_left));
    sort(rall(a_right));
    sort(all(b));

    int l = 0, r = 2e9;
    while (l < r) {
        int mi = l + (r - l) / 2;

        int a_i = 0, b_li = 0;
        for (; a_i < sz(a_left) && b_li < k; b_li++) {
            int dist = p - a_left[a_i];
            if (p < b[b_li])
                dist += 2 * (b[b_li] - p);
            else if (b[b_li] < a_left[a_i])
                dist += 2 * (a_left[a_i] - b[b_li]);

            if (dist <= mi) a_i++;
        }
        if (a_i != sz(a_left)) {
            l = mi + 1;
            continue;
        }

        int b_ri = k - 1;
        for (a_i = 0; a_i < sz(a_right) && b_ri >= b_li; b_ri--) {
            int dist = -p + a_right[a_i];
            if (p > b[b_ri])
                dist -= 2 * (b[b_ri] - p);
            else if (b[b_ri] > a_right[a_i])
                dist -= 2 * (a_right[a_i] - b[b_ri]);

            if (dist <= mi) a_i++;
        }
        if (a_i != sz(a_right)) {
            l = mi + 1;
            continue;
        }

        r = mi;
    }

    cout << l;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}