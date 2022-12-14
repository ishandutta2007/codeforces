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
#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

int main() {
    ioThings();

    vector<int> st(3);
    for (int i = 0; i < 3; i++) {
        string s; cin >> s;
        if (s[1] == '>')
            st[s[0] - 'A']++;
        else
            st[s[2] - 'A']++;
    }

    string ans(3, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (st[j] == i) {
                if (ans[i]) {
                    cout << "Impossible";
                    return 0;
                } else
                    ans[i] = j + 'A';
            }
        }
    }
    
    cout << ans;

    return 0;
}