#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int test;
vector<int> mpref, msuf, rpref, rsuf;
LL mcnt, rcnt;
int n, k, m;
int a[200000], inp[200000];

vector<int> tmp;
void mul(vector<int> &p, vector<int> &suf, vector<int> &pref, vector<int> &s, vector<int> &rpref, vector<int> &rsuf, LL a, LL b, LL &c) {
    int ind = (int)suf.size() - 1;
    int jnd = 0;
    while (ind >= 0) {
        int iind = ind;
        int jjnd = jnd;
        int cnt = 0;
        while (cnt < k && iind >= 0 && suf[iind] == suf[ind]) {
            ++cnt;
            --iind;
        }
        while (cnt < k && jjnd < (int)pref.size() && pref[jjnd] == suf[ind]) {
            ++cnt;
            ++jjnd;
        }
        if (cnt == k) {
            ind = iind;
            jnd = jjnd;
        } else {
            break;
        }
    }
    a -= (int)suf.size() - 1 - ind;
    b -= jnd;
    tmp.clear();
    int aa = min(a, (LL)p.size());
    forn(i, aa) {
        tmp.pb(p[i]);
    }
    int bb = min(b, (LL)s.size());
    forn(i, bb) {
        tmp.pb(s[(int)s.size() - bb + i]);
    }
    c = a + b;
    aa = min(2 * n + 111, (int)tmp.size());
    rpref.clear();
    rsuf.clear();
    forn(i, aa) rpref.pb(tmp[i]);
    forn(i, aa) rsuf.pb(tmp[(int)tmp.size() - aa + i]);
}

void binPow(int p) {
    rpref.clear();
    rsuf.clear();
    rcnt = 0;
    while (p) {
        if (p & 1) mul(rpref, rsuf, mpref, msuf, rpref, rsuf, rcnt, mcnt, rcnt);
        p >>= 1;
        if (p) mul(mpref, msuf, mpref, msuf, mpref, msuf, mcnt, mcnt, mcnt);
    }
}

vector<int> st;

LL solve() {
    int last = -1;
    int cnt = 0;
    st.clear();
    int pos = 0;
    int nn = n;
    for (int i = 0; i < n; ++i) {
        a[i] = inp[pos++];
        if (a[i] != last) {
            if (last != -1) {
                st.pb(cnt);
            }
            last = a[i];
            cnt = 0;
        }
        if (++cnt == k) {
            i -= k;
            n -= k;
            if (st.empty()) {
                last = -1;
                cnt = 0;
            } else {
                last = a[i];
                cnt = st.back();
                st.pop_back();
            }
        }
    }
    if (st.empty()) {
        n = nn;
        return (LL)n * m % k;
    }
    mpref.clear();
    msuf.clear();
    forn(i, n) mpref.pb(a[i]);
    forn(i, n) msuf.pb(a[i]);
    mcnt = n;
    binPow(m);
    n = nn;
    return rcnt;
}

void readTest() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", inp + i);
    }
}

mt19937 mt(123);
void genTest() {
    n = mt() % 25 + 1;
    k = mt() % 25 + 1;
    m = mt() % 25 + 1;
    int cnt = mt() % 25 + 1;
    forn(i, n) {
        inp[i] = mt() % cnt + 1;
    }
}

LL brute() {
    int last = -1;
    int cnt = 0;
    st.clear();
    int nn = n;
    int ind = 0;
    forn(_, m) {
        int pos = 0;
        n = ind + nn;
        for (int i = ind; i < n; ++i) {
            a[i] = inp[pos++];
            if (a[i] != last) {
                if (last != -1) {
                    st.pb(cnt);
                }
                last = a[i];
                cnt = 0;
            }
            if (++cnt == k) {
                i -= k;
                n -= k;
                if (st.empty()) {
                    last = -1;
                    cnt = 0;
                } else {
                    last = a[i];
                    cnt = st.back();
                    st.pop_back();
                }
            }
        }
        ind = n;
    }
    n = nn;
    return ind;
}

//int main() {
//    for (test = 0; test < 12341234; ++test) {
//        genTest();
//        auto sol = solve();
//        auto br = brute();
//        if (sol != br) {
//            printf("WA %d\n", test);
//            printf("%d %d %d\n", n, k, m);
//            forn(i, n) printf("%d ", inp[i]);
//            puts("");
//            printf("sol %d br %d\n", (int)sol, (int)br);
//            return 0;
//        }
//        if (!(test & 1023)) {
//            printf("OK %d\n", test);
//        }
//    }
//    return 0;
//}

int main() {
    readTest();
    cout << solve() << endl;
    return 0;
}