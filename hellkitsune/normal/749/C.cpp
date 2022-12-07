#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[200005];
set<int> d, r, all;

int main() {
    scanf("%d%s", &n, s);
    forn(i, n) if (s[i] == 'D') {
        d.insert(i);
    } else {
        r.insert(i);
    }
    forn(i, n) {
        all.insert(i);
    }
    int nx = 0;
    while (!d.empty() && !r.empty()) {
        auto it = all.lower_bound(nx);
        if (it == all.end()) {
            it = all.begin();
        }
        int ind = *it;
        nx = ind + 1;
        if (s[ind] == 'D') {
            auto it = r.lower_bound(ind);
            if (it == r.end()) {
                it = r.begin();
            }
            int er = *it;
            r.erase(it);
            all.erase(er);
        } else {
            auto it = d.lower_bound(ind);
            if (it == d.end()) {
                it = d.begin();
            }
            int er = *it;
            d.erase(it);
            all.erase(er);
        }
    }
    if (d.empty()) {
        cout << "R" << endl;
    } else {
        cout << "D" << endl;
    }
    return 0;
}