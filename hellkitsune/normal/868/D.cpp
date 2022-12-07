#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 11;

int n;
string pref[200], suf[200];
vector<string> v[200];
int ans[200];
string t[2 << MX];
int cnt;

inline int solve(const string &s, int x) {
    while (true) {
        if (s.find(t[x]) == string::npos) {
            break;
        }
        ++x;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 1; i <= MX; ++i) {
        forn(mask, 1 << i) {
            string tmp;
            forn(j, i) if (mask & (1 << j)) {
                tmp.pb('1');
            } else {
                tmp.pb('0');
            }
            t[cnt++] = tmp;
        }
    }
    cin >> n;
    forn(i, n) {
        string s;
        cin >> s;
        v[i].pb(s);
        ans[i] = solve(s, 0);
        if ((int)s.size() <= MX) {
            pref[i] = suf[i] = s;
        } else {
            pref[i] = s.substr(0, MX);
            suf[i] = s.substr((int)s.size() - MX);
        }
    }
    int ind = n;
    int q;
    cin >> q;
    forn(_, q) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        for (string x : v[a]) v[ind].pb(x);
        for (string x : v[b]) v[ind].pb(x);
        string s = suf[a] + pref[b];
        v[ind].pb(s);
        sort(v[ind].begin(), v[ind].end());
        v[ind].erase(unique(v[ind].begin(), v[ind].end()), v[ind].end());
        pref[ind] = pref[a] + pref[b];
        if ((int)pref[ind].size() > MX) {
            pref[ind].resize(MX);
        }
        suf[ind] = suf[a] + suf[b];
        if ((int)suf[ind].size() > MX) {
            suf[ind] = suf[ind].substr((int)suf[ind].size() - MX);
        }
        int res = max(ans[a], ans[b]);
        while (true) {
            int nres = res;
            for (const string &x : v[ind]) {
                nres = solve(x, nres);
            }
            if (nres == res) break;
            res = nres;
        }
        ans[ind] = res;
        cout << (int)t[ans[ind]].size() - 1 << '\n';
        ++ind;
    }
    return 0;
}