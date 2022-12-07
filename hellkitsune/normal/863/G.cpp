#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[6], b[6], ord[6], c[6];
vector<PII> v, nv;

struct S {
    vector<PII> v;
    int from;
    S(vector<PII> v, int from) : v(v), from(from) {}
    S() {}
};

vector<S> s;

void pr(int a, int b) {
    if (a == 1) {
        printf("inc %d\n", ord[b] + 1);
    } else {
        printf("dec %d\n", ord[b] + 1);
    }
}

S hor, ver, res;

bool invI, invJ;

void _incI() {
    assert(ver.from < (int)ver.v.size());
    res.v.pb(ver.v[ver.from++]);
}

void _decI() {
    assert(ver.from > 0);
    PII p = ver.v[--ver.from];
    p.first = -p.first;
    res.v.pb(p);
}

void _incJ() {
    assert(hor.from < (int)hor.v.size());
    res.v.pb(hor.v[hor.from++]);
}

void _decJ() {
    assert(hor.from > 0);
    PII p = hor.v[--hor.from];
    p.first = -p.first;
    res.v.pb(p);
}

void decI() {
    if (invI) _incI();
    else _decI();
}

void incI() {
    if (invI) _decI();
    else _incI();
}

void decJ() {
    if (invJ) _incJ();
    else _decJ();
}

void incJ() {
    if (invJ) _decJ();
    else _incJ();
}

S merge() {
    res.v.clear();
    res.from = 0;
    int i = ver.from;
    int j = hor.from;
    int n = (int)ver.v.size() + 1;
    int m = (int)hor.v.size() + 1;
    assert(i % 2 == j % 2);
    invI = invJ = false;
    if (i % 2 == 1) {
        for (int jj = j; jj >= 0; --jj) {
            if (jj & 1) {
                forn(_, i) decI();
            } else {
                forn(_, i) incI();
            }
            if (jj != 0) decJ();
            else incI();
        }
        for (int ii = i + 1; ii < n; ++ii) {
            if (ii & 1) {
                forn(_, j) decJ();
            } else {
                forn(_, j) incJ();
            }
            if (ii != n - 1) incI();
            else incJ();
        }
        for (int jj = j + 1; jj < m; ++jj) {
            if (jj & 1) {
                forn(_, n - 1) incI();
            } else {
                forn(_, n - 1) decI();
            }
            if (jj != m - 1) incJ();
        }
    } else {
        if (i == n - 1) {
            i = 0;
            invI = true;
        }
        if (j == 0) {
            j = m - 1;
            invJ = true;
        }
        forn(_, i) decI();
        decJ();
        forn(ii, i + 1) {
            if (ii & 1) {
                forn(_, j - 1) incJ();
            } else {
                forn(_, j - 1) decJ();
            }
            incI();
        }
        forn(jj, j + 1) {
            if (jj & 1) {
                forn(_, n - i - 2) decI();
            } else {
                forn(_, n - i - 2) incI();
            }
            if (jj != j) incJ();
        }
        if (j != m - 1) {
            incJ();
            for (int jj = j + 1; jj < m; ++jj) {
                if (jj & 1) {
                    forn(_, n - 1) decI();
                } else {
                    forn(_, n - 1) incI();
                }
                if (jj != m - 1) incJ();
            }
        }
    }
    return res;
}

int main() {
    cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    if (n == 1) {
        if (a[0] == 2) {
            cout << "Cycle" << endl;
            if (b[0] == 1) {
                cout << "inc 1" << endl;
                cout << "dec 1" << endl;
            } else {
                cout << "dec 1" << endl;
                cout << "inc 1" << endl;
            }
        } else {
            if (b[0] == 1) {
                cout << "Path" << endl;
                forn(i, a[0] - 1) {
                    cout << "inc 1\n";
                }
            } else if (b[0] == a[0]) {
                cout << "Path" << endl;
                forn(i, a[0] - 1) {
                    cout << "dec 1\n";
                }
            } else {
                cout << "No" << endl;
            }
        }
        return 0;
    }
    forn(i, n) ord[i] = i;
    forn(i, n - 1) if (a[i] % 2 == 0) {
        swap(a[i], a[n - 1]);
        swap(b[i], b[n - 1]);
        swap(ord[i], ord[n - 1]);
        break;
    }
    if (a[n - 1] % 2 == 0) {
        forn(i, n - 1) {
            nv.clear();
            forn(j, a[i]) {
                if (j & 1) {
                    reverse(v.begin(), v.end());
                    for (PII p : v) {
                        nv.pb(mp(-p.first, p.second));
                    }
                    reverse(v.begin(), v.end());
                } else {
                    for (PII p : v) {
                        nv.pb(p);
                    }
                }
                if (j != a[i] - 1) {
                    nv.pb(mp(1, i));
                }
            }
            v = nv;
        }
        nv.clear();
        for (PII p : v) {
            nv.pb(p);
        }
        forn(i, a[n - 1] - 1) {
            nv.pb(mp(1, n - 1));
            if (i & 1) {
                for (int j = 1; j < (int)v.size(); ++j) {
                    nv.pb(v[j]);
                }
            } else {
                for (int j = (int)v.size() - 1; j >= 1; --j) {
                    nv.pb(mp(-v[j].first, v[j].second));
                }
            }
        }
        nv.pb(mp(-v[0].first, v[0].second));
        forn(i, a[n - 1] - 1) {
            nv.pb(mp(-1, n - 1));
        }
        forn(i, n) c[i] = 1;
        v = nv;

        int ind = 0;
        while (true) {
            bool ok = true;
            forn(j, n) if (c[j] != b[j]) {
                ok = false;
                break;
            }
            if (ok) break;
            c[v[ind].second] += v[ind].first;
            ++ind;
        }
        printf("Cycle\n");
        for (int i = ind; i < (int)v.size(); ++i) {
            pr(v[i].first, v[i].second);
        }
        for (int i = 0; i < ind; ++i) {
            pr(v[i].first, v[i].second);
        }
        return 0;
    }
    int sum = 0;
    forn(i, n) sum += b[i] - 1;
    if (sum % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Path" << endl;
    forn(i, n) {
        vector<PII> cur;
        forn(j, a[i] - 1) {
            cur.pb(mp(1, i));
        }
        s.pb(S(cur, b[i] - 1));
    }
    while ((int)s.size() > 1) {
        bool done = false;
        forn(i, s.size()) {
            forn(j, i) {
                if ((s[i].from + s[j].from) % 2 == 0) {
                    hor = s[i];
                    ver = s[j];
                    s[i] = merge();
                    swap(s[j], s.back());
                    s.pop_back();
                    done = true;
                    break;
                }
            }
            if (done) {
                break;
            }
        }
        assert(done);
    }
    for (PII p : s[0].v) {
        pr(p.first, p.second);
    }
    return 0;
}