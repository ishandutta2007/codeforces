#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[100005];
vector<vector<int> > ll, lr, rl, rr;
set<int> l, r;

void printV(vector<int> &v) {
    for (int x : v) printf("%d ", x + 1);
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) if (s[i] == 'L') l.insert(i);
    else r.insert(i);
    while (!l.empty() || !r.empty()) {
        bool stL, endL, curL = stL = r.empty() || (!l.empty() && *l.begin() < *r.begin());
        vector<int> v;
        int pos = -1;
        while (true) {
            if (curL) {
                auto it = l.lower_bound(pos);
                if (it == l.end()) break;
                v.pb(*it);
                pos = *it + 1;
                l.erase(it);
            } else {
                auto it = r.lower_bound(pos);
                if (it == r.end()) break;
                v.pb(*it);
                pos = *it + 1;
                r.erase(it);
            }
            curL = !curL;
        }
        endL = !curL;
        if (stL && endL) ll.pb(v);
        else if (stL && !endL) lr.pb(v);
        else if (!stL && endL) rl.pb(v);
        else rr.pb(v);
    }
    int cnt = (int)(ll.size() + lr.size() + rl.size() + rr.size());
    if (ll.empty() && rr.empty() && !lr.empty() && !rl.empty()) {
        vector<int> vlr = lr.back();
        lr.pop_back();
        vector<int> vrl = rl.back();
        rl.pop_back();
        if (vlr.back() > vrl.back()) {
            vrl.pb(vlr.back());
            vlr.pop_back();
        } else {
            vlr.pb(vrl.back());
            vrl.pop_back();
        }
        rr.pb(vrl);
        ll.pb(vlr);
    }
    printf("%d\n", cnt - 1);
    if (ll.size() > rr.size()) {
        for (vector<int> &v : lr) printV(v);
        printV(ll.back());
        ll.pop_back();
        for (vector<int> &v : rl) printV(v);
        while (!rr.empty()) {
            printV(rr.back());
            rr.pop_back();
            if (!ll.empty()) {
                printV(ll.back());
                ll.pop_back();
            }
        }
        if (!ll.empty()) printV(ll.back());
    } else if (!rr.empty()) {
        for (vector<int> &v : rl) printV(v);
        printV(rr.back());
        rr.pop_back();
        for (vector<int> &v : lr) printV(v);
        while (!ll.empty()) {
            printV(ll.back());
            ll.pop_back();
            if (!rr.empty()) {
                printV(rr.back());
                rr.pop_back();
            }
        }
        if (!rr.empty()) printV(rr.back());
    } else {
        for (vector<int> &v : lr) printV(v);
        for (vector<int> &v : rl) printV(v);
    }
    printf("\n");
    return 0;
}