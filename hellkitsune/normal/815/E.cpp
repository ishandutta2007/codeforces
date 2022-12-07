#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n, k, rem;
vector<PLL> v, nv;
LL a, b;

LL calc(LL x, LL need) {
    map<LL, LL> ma;
    ma[x] = 1;
    while (true) {
        auto it = ma.end();
        --it;
        LL val = it->first;
        LL cnt = it->second;
        if (val == need) {
            return cnt;
        }
        if (val < need) {
            return 0;
        }
        ma.erase(it);
        ma[(val - 1) / 2] += cnt;
        ma[val / 2] += cnt;
    }
    return -1;
}

void sol1(LL len, LL pos) {
    if (len == a) {
        assert(rem == 1);
        cout << pos + (len - 1) / 2 << endl;
        exit(0);
    }
    LL mid = pos + (len - 1) / 2;
    LL le = (len - 1) / 2;
    LL ri = len / 2;
    LL cnt = calc(le, a);
    if (rem <= cnt) {
        sol1(le, pos);
    } else {
        rem -= cnt;
        sol1(ri, mid + 1);
    }
}

void sol2(LL len, LL pos) {
    if (len == a || len == b) {
        assert(rem == 1 || rem == 2);
        cout << pos + (len - 1) / 2 + rem - 1 << endl;
        exit(0);
    }
    LL mid = pos + (len - 1) / 2;
    LL le = (len - 1) / 2;
    LL ri = len / 2;
    LL cnt = calc(le, a) + calc(le, b);
    if (rem <= cnt) {
        sol2(le, pos);
    } else {
        rem -= cnt;
        sol2(ri, mid + 1);
    }
}

void solve1(LL a) {
    ::a = a;
    sol1(n - 2, 2);
}

void solve2(LL a, LL b) {
    ::a = a;
    ::b = b;
    sol2(n - 2, 2);
}

int main() {
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (k == 2) {
        cout << n << endl;
        return 0;
    }
    k -= 2;
    v.pb(mp(n - 2, 1));
    rem = k;
    while (true) {
        if ((int)v.size() == 1) {
            if (v[0].first % 2 == 0) {
                v.pb(mp(v[0].first - 1, 0));
                sort(v.begin(), v.end());
            } else {
                v.pb(mp(v[0].first + 1, 0));
            }
        }
        map<LL, LL> ma;
        if ((v[0].first - 1) / 2 == (v[1].first - 1) / 2) {
            if (v[0].first != 1) {
                if (rem <= v[0].second + v[1].second) {
                    solve2(v[0].first, v[1].first);
                }
                forn(i, 2) {
                    ma[(v[i].first - 1) / 2] += v[i].second;
                    ma[v[i].first / 2] += v[i].second;
                }
            } else {
                solve2(v[0].first, v[1].first);
            }
            rem -= v[0].second + v[1].second;
        } else {
            if (rem <= v[1].second) {
                solve1(v[1].first);
            }
            rem -= v[1].second;
            ma[(v[1].first - 1) / 2] += v[1].second;
            ma[v[1].first / 2] += v[1].second;
            ma[v[0].first] += v[0].second;
        }
        nv.clear();
        for (auto p : ma) {
            if (p.first > 0) {
                nv.pb(p);
            }
        }
        v = nv;
    }
    return 0;
}