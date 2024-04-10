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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int qry(vector<int> a, vector<int> b) {
    cout << "? " << a.size() << " " << b.size() << "\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " \n"[i+1 == a.size()];
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " \n"[i+1 == b.size()];
    cout.flush();
    int f; cin >> f; return f;
}

void submit(vector<int> a) {
    cout << "! " << a.size();
    for (auto& x : a) cout << " " << x;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int p = 2;
        while (1) {
            vector<int> a(p-1), b = {p};
            iota(all(a), 1);
            if (qry(a, b) != 0) break;
            p++;
        }
        vector<int> ans;
        for (int i = p+1; i <= n; i++)
            if (qry({p}, {i}) == 0) ans.pb(i);
        int x = 1, k = 1;
        while (2*k < n) k *= 2;
        debug(p);
        debug(k);
        for (; k > 0; k /= 2) {
            if (x+k >= p) continue;
            vector<int> a(p-(x+k)), b = {p};
            iota(all(a), x+k);
            if (qry(a, b) != 0) x += k;
        }
        debug(x);
        for (int i = 1; i < p; i++)
            if (i != x) ans.pb(i);
        submit(ans);
    }
}