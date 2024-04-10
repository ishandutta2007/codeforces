#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// Knuth-Morris-Pratt algorithm. Returns a list of all indices at which W appears in S.
// Runs in O(|S|+|W|) time.
template<typename it>
vector<int> kmp(it S_first, it S_last, it W_first, it W_last) {
    int n = S_last-S_first, m = W_last-W_first;
    vector<int> out, ptr(m+1);
    ptr[0] = -1;
    for (int i = 1, j = 0; i < m; i++, j++) {
        if (W_first[i] == W_first[j])
            ptr[i] = ptr[j];
        else {
            ptr[i] = j;
            do
                j = ptr[j];
            while (j >= 0 && W_first[i] != W_first[j]);
        }
        if (i == m-1) ptr[m] = j+1;
    }
    for (int i = 0, j = 0; i < n;) {
        if (W_first[j] == S_first[i]) {
            i++, j++;
            if (j == m) {
                out.push_back(i-j);
                j = ptr[j];
            }
        } else {
            j = ptr[j];
            if (j < 0) i++, j++;
        }
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        bool ok = 0;
        for (int i = 0; i < a.size(); i++) {
            string x = a.substr(0, i+1);
            string y = x;
            x.pop_back();
            reverse(all(y));
            x += y;
            if (kmp(all(x), all(b)).size() > 0) ok = 1;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}