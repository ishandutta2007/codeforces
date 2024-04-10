#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
    freopen("io\\err.txt", "w", stderr);
#endif
}

using   ll        = long long;
#define debug(x)    cerr << #x << ": <" << x << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

#define gc(x) ((x) - 'a')

vector<set<int>> adj(26);
string key;
vector<bool> added(26);

void dfs(int cur) {
    if (added[cur])
        return;
    added[cur] = true;
    key += cur + 'a';
    for (auto& i : adj[cur])
        dfs(i);
}


int main() {
    ioThings();

    dotc() {
        string s; cin >> s;
        bool ok = true;
        bool noKeys = true;
        for (int i = 1; i < sz(s); i++) {
            if (s[i - 1] == s[i])
                continue;
            if (noKeys)
                noKeys = false;
            adj[gc(s[i - 1])].insert(gc(s[i]));
            adj[gc(s[i])].insert(gc(s[i - 1]));
            if (sz(adj[gc(s[i - 1])]) > 2 || sz(adj[gc(s[i])]) > 2) {
                ok = false;
                break;
            }
        }

        if (ok) {
            bool loop = true;
            for (int i = 0; i < 26; i++)
                if (sz(adj[i]) == 1) {
                    dfs(i);
                    loop = false;
                    break;
                }
            if (key.empty() && !noKeys)
                cout << "NO\n";
            else {
                cout << "YES\n";
                for (int i = 0; i < 26; i++)
                    if (!added[i])
                        key += i + 'a';
                cout << key << '\n';
            }
        } else
            cout << "NO\n";

        for (auto& i : adj)
            i.clear();
        key.clear();
        added.clear();
        added.resize(26);
    }

    return 0;
}