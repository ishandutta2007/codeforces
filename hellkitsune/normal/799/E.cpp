#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = LL(1e18);

int n, m, k;
int c[200000], a[200000], b[200000];
multiset<int> z, f, s;
multiset<int, greater<int> > zz, ff, ss;
vector<int> both;

void readArr(int *a) {
    int cnt;
    cin >> cnt;
    forn(i, cnt) {
        int x;
        cin >> x;
        --x;
        a[x] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    forn(i, n) cin >> c[i];
    readArr(a);
    readArr(b);
    forn(i, n) {
        if (a[i] == 0 && b[i] == 0) {
            z.insert(c[i]);
        } else if (a[i] == 0 && b[i] == 1) {
            s.insert(c[i]);
        } else if (a[i] == 1 && b[i] == 0) {
            f.insert(c[i]);
        } else {
            both.pb(c[i]);
        }
    }
    sort(both.begin(), both.end());
    if ((int)both.size() > m) {
        both.resize(m);
    }
    LL ans = INF;
    LL cost = 0;
    int ac, bc, cnt;
    ac = bc = cnt = (int)both.size();
    forn(i, both.size()) {
        cost += both[i];
    }
    bool ok = true;
    for (int i = (int)both.size(); i >= 0; --i) {
        if (i < (int)both.size()) {
            cost -= both[i];
            --ac;
            --bc;
            --cnt;
        }

        while (cnt < m) {
            int flag = -1;
            int best = int(2e9);
            if (!f.empty() && *f.begin() < best) {
                best = *f.begin();
                flag = 1;
            }
            if (!s.empty() && *s.begin() < best) {
                best = *s.begin();
                flag = 2;
            }
            if (!z.empty() && *z.begin() < best) {
                best = *z.begin();
                flag = 0;
            }
            if (flag == -1) {
                ok = false;
                break;
            }
            cost += best;
            if (flag == 0) {
                zz.insert(*z.begin());
                z.erase(z.begin());
            } else if (flag == 1) {
                ff.insert(*f.begin());
                f.erase(f.begin());
                ++ac;
            } else {
                ss.insert(*s.begin());
                s.erase(s.begin());
                ++bc;
            }
            ++cnt;
        }
        if (!ok) {
            break;
        }
        while (ac < k) {
            if (f.empty()) {
                ok = false;
                break;
            }
            int flag = -1;
            int best = -1;
            if (!zz.empty() && *zz.begin() > best) {
                best = *zz.begin();
                flag = 0;
            }
            if (bc > k && !ss.empty() && *ss.begin() > best) {
                best = *ss.begin();
                flag = 2;
            }

            if (flag == -1) {
                ok = false;
                break;
            }
            cost -= best;
            if (flag == 0) {
                z.insert(best);
                zz.erase(zz.begin());
            } else {
                s.insert(best);
                ss.erase(ss.begin());
                --bc;
            }
            cost += *f.begin();
            ff.insert(*f.begin());
            f.erase(f.begin());
            ++ac;
        }
        if (!ok) {
            break;
        }
        while (bc < k) {
            if (s.empty()) {
                ok = false;
                break;
            }
            int flag = -1;
            int best = -1;
            if (!zz.empty() && *zz.begin() > best) {
                best = *zz.begin();
                flag = 0;
            }
            if (ac > k && !ff.empty() && *ff.begin() > best) {
                best = *ff.begin();
                flag = 2;
            }

            if (flag == -1) {
                ok = false;
                break;
            }
            cost -= best;
            if (flag == 0) {
                z.insert(best);
                zz.erase(zz.begin());
            } else {
                f.insert(best);
                ff.erase(ff.begin());
                --ac;
            }
            cost += *s.begin();
            ss.insert(*s.begin());
            s.erase(s.begin());
            ++bc;
        }
        if (!ok) {
            break;
        }
        ans = min(ans, cost);
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}