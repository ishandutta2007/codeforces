#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

vector<int> p;
vector<int> q;
int n;

int ask(int i) {
    #ifdef LOCAL
        // for (int i : q)
        //     cout << i << ' ';
        // cout << '\n';
        // cout << "Ask " << i + 1 << '\n';
        int res = q[i];
        vector<int> tmp(n);
        for (int i = 0; i < n; ++i)
            tmp[i] = q[p[i] - 1];
        q = tmp;
        return res;
    #else
        cout << "? " << i + 1 << endl;
        int res;
        cin >> res;
        return res - 1;
    #endif
}

void solve() {
    cin >> n;
    #ifdef LOCAL
        p.resize(n);
        q.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        iota(all(q), 0);
    #endif
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (ans[i] == -1) {
            vector<int> tmp;
            int now = ask(i);
            while (now != i) {
                now = ask(i);
            }
            now = ask(i);
            int lst = i;
            // cout << i << ':';
            // cout << i << ' ';
            while (now != i) {
                // cout << lst << ',' << now << ' ';
                ans[lst] = now;
                lst = now;
                now = ask(i);
            }
            // cout << '\n';
            ans[lst] = i;
        }
    }
    cout << "! ";
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << endl;
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