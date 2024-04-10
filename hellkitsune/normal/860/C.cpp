#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string a[200005];
int b[200005];
char buf[15];
set<string> one, zero, wone, wzero, needOne, needZero;
set<string> all;

mt19937 mt(time(0));

string gen() {
    string s;
    forn(i, 6) {
        int z = mt() % 36;
        if (z < 26) {
            s.pb(char('a' + z));
        } else {
            s.pb(char('0' + (z - 26)));
        }
    }
    return s;
}

vector<pair<string, string> > ans;

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) {
        scanf("%s", buf);
        a[i] = string(buf);
        all.insert(a[i]);
        scanf("%d", b + i);
    }
    int oc = 0;
    forn(i, n) oc += b[i];
    for (int i = 1; i <= n; ++i) {
        ostringstream oss;
        oss << i;
        if (i <= oc) {
            one.insert(oss.str());
        } else {
            zero.insert(oss.str());
        }
    }
    forn(i, n) if (b[i] == 1) {
        if (one.count(a[i])) {
            one.erase(a[i]);
        } else if (zero.count(a[i])) {
            zero.erase(a[i]);
            wzero.insert(a[i]);
        } else {
            needOne.insert(a[i]);
        }
    } else {
        if (zero.count(a[i])) {
            zero.erase(a[i]);
        } else if (one.count(a[i])) {
            one.erase(a[i]);
            wone.insert(a[i]);
        } else {
            needZero.insert(a[i]);
        }
    }
    while (true) {
        if (!one.empty()) {
            if (!wzero.empty()) {
                string s = *wzero.begin();
                string t = *one.begin();
                wzero.erase(wzero.begin());
                one.erase(one.begin());
                ans.pb(mp(s, t));
                zero.insert(s);
            } else {
                assert(!needOne.empty());
                string s = *needOne.begin();
                string t = *one.begin();
                needOne.erase(needOne.begin());
                one.erase(one.begin());
                ans.pb(mp(s, t));
            }
        } else if (!zero.empty()) {
            if (!wone.empty()) {
                string s = *wone.begin();
                string t = *zero.begin();
                wone.erase(wone.begin());
                zero.erase(zero.begin());
                ans.pb(mp(s, t));
                one.insert(s);
            } else {
                assert(!needZero.empty());
                string s = *needZero.begin();
                string t = *zero.begin();
                needZero.erase(needZero.begin());
                zero.erase(zero.begin());
                ans.pb(mp(s, t));
            }
        } else {
            assert((int)wone.size() == (int)wzero.size());
            assert(needOne.empty());
            assert(needZero.empty());
            if (!wone.empty()) {
                string tmp;
                do {
                    tmp = gen();
                } while (all.count(tmp));
                string can = *wone.begin();
                wone.erase(wone.begin());
                ans.pb(mp(can, tmp));
                while (!wone.empty()) {
                    string s = *wzero.begin();
                    wzero.erase(wzero.begin());
                    ans.pb(mp(s, can));
                    can = *wone.begin();
                    wone.erase(wone.begin());
                    ans.pb(mp(can, s));
                }
                string s = *wzero.begin();
                wzero.erase(wzero.begin());
                ans.pb(mp(s, can));
                assert(wzero.empty());
                ans.pb(mp(tmp, s));
            }
            break;
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto p : ans) {
        printf("move %s %s\n", p.first.c_str(), p.second.c_str());
    }
    return 0;
}