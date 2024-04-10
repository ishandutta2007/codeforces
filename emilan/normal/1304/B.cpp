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

    int n, m; cin >> n >> m;
    vector<string> pali;
    map<string, int> selfPali;
    map<string, int> missing;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string rev(rall(s));
        if (missing[rev]) {
            if (selfPali[rev])
                selfPali[rev]--;
            missing[rev]--;
            pali.pb(rev);
        } else {
            string l(s.begin(), s.begin() + sz(s) / 2);
            string r(s.rbegin(), s.rbegin() + sz(s) / 2);
            if (l == r) 
                selfPali[s]++;
            missing[s]++;
        }
    }

    string res;
    for (auto& i : pali)
        res += i;
    string resRev(rall(res));

    for (auto& i : selfPali)
        if (i.se) {
            res += i.fi;
            break;
        }
    res += resRev;
        
    cout << sz(res) << '\n' << res;

    return 0;
}