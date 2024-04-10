#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<int> h(n);
    for (int &i : h) cin >> i;

    vt<int> jumps(n);
    vt<int> hi{0}, lo{0};
    for (int i = 1; i < n; i++) {
        jumps[i] = jumps[i - 1] + 1;
        while (!hi.empty() && h[hi.back()] < h[i]) {
            jumps[i] = min(jumps[i], jumps[hi.back()] + 1);
            hi.pop_back();
        }
        while (!lo.empty() && h[lo.back()] > h[i]) {
            jumps[i] = min(jumps[i], jumps[lo.back()] + 1);
            lo.pop_back();
        }

        if (!hi.empty()) jumps[i] = min(jumps[i], jumps[hi.back()] + 1);
        if (!lo.empty()) jumps[i] = min(jumps[i], jumps[lo.back()] + 1);

        if (!hi.empty() && h[hi.back()] == h[i]) hi.pop_back();
        if (!lo.empty() && h[lo.back()] == h[i]) lo.pop_back();

        hi.push_back(i);
        lo.push_back(i);
    }

    cout << jumps.back();
}