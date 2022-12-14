#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi par(26, -1);
    rep(i, n) {
        string s;
        cin >> s;
        set<char> charset;
        for (char c : s) charset.insert(c);

        int to = *charset.begin() - 'a';
        if (par[to] == -1) par[to] = to;
        
        for (char c : charset) {
            int i = c - 'a';
            if (par[i] == -1) par[i] = to;
            else {
                int from = par[i];
                rep(j, 26) {
                    if (par[j] == from) par[j] = to;
                }
            }
        }
    }

    set<int> g;
    rep(i, 26) g.insert(par[i]);
    g.erase(-1);
    cout << sz(g);

    return 0;
}