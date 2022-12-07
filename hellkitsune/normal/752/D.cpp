#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, len;
map<string, vector<int> > ma;
int mx = 0;
int ans = 0;
char buf[100005];
string s[100005];

int main() {
    scanf("%d%d", &n, &len);
    forn(i, n) {
        int x;
        scanf("%s%d", buf, &x);
        ma[string(buf)].pb(x);
    }
    for (auto &p : ma) {
        string rev = p.first;
        reverse(rev.begin(), rev.end());

        vector<int> &v = p.second;
        sort(v.begin(), v.end(), greater<int>());

        if (rev == p.first) {
            int pos = 0;
            int sz = int(v.size());
            while (pos < sz - 1 && v[pos + 1] >= 0) {
                ans += v[pos];
                ans += v[pos + 1];
                pos += 2;
            }
            if (pos < sz && v[pos] > 0) {
                if (pos < sz - 1 && v[pos] + v[pos + 1] > 0) {
                    ans += v[pos];
                    ans += v[pos + 1];
                    mx = max(mx, -v[pos + 1]);
                } else {
                    mx = max(mx, v[pos]);
                }
            }
        } else if (rev > p.first) {
            vector<int> &u = ma[rev];
            sort(u.begin(), u.end(), greater<int>());
            int sz = int(min(u.size(), v.size()));
            forn(i, sz) if (u[i] + v[i] > 0) {
                ans += u[i] + v[i];
            }
        }
    }
    cout << ans + mx << endl;
    return 0;
}