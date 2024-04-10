#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int N = 4e5 + 7;
const int K = 20;

int go[N][K];
int up[N][K];
ll sm[N][K];
int mx[N][K];
int w[N];
int h[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    int ptr = 0;
    int last = 0;
    while (q--) {
        int t;
        cin >> t;
        ll qx, px;
        cin >> qx >> px;
        int r = qx ^ last;
        ll x = px ^ last;
        --r;
        if (t == 1) {
            ++ptr;
            go[ptr][0] = r;
            mx[ptr][0] = w[r];
            w[ptr] = x;
            for (int k = 1; k < K; ++k) {
                go[ptr][k] = go[go[ptr][k - 1]][k - 1];
                mx[ptr][k] = max(mx[ptr][k - 1], mx[go[ptr][k - 1]][k - 1]);
            }
            int cur = ptr;
            for (int k = K - 1; k >= 0; --k) {
                if (mx[cur][k] < x) cur = go[cur][k];
            }
            cur = go[cur][0];
            if (w[cur] >= x) {
                up[ptr][0] = cur;
                sm[ptr][0] = w[cur];
                h[ptr] = h[cur] + 1;
                for (int k = 1; k < K; ++k) {
                    up[ptr][k] = up[up[ptr][k - 1]][k - 1];
                    sm[ptr][k] = sm[ptr][k - 1] + sm[up[ptr][k - 1]][k - 1];
                }
            }
            else {
                h[ptr] = 0;
                for (int k = 0; k < K; ++k) {
                    up[ptr][k] = ptr;
                    sm[ptr][k] = 0;
                }
            }
        }
        else {
            int ans = 0;
            int cur = r;
            if (w[r] <= x) {
                ++ans;
                x -= w[r];
                for (int k = K - 1; k >= 0; --k) {
                    if (sm[cur][k] <= x) {
                        x -= sm[cur][k];
                        cur = up[cur][k];
                    }
                }
                ans += h[r] - h[cur];
            }
            cout << ans << "\n";
            last = ans;
        }
    }
}