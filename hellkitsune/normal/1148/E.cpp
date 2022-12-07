#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
PII a[300000];
int b[300000];

vector<int> le, ri;

void cleanUp() {
    while (!ri.empty() && a[ri.back()].first == b[ri.back()]) {
        ri.pop_back();
    }
}

vector<pair<PII, int> > ans;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }
    forn(i, n) {
        scanf("%d", b + i);
    }
    sort(a, a + n);
    sort(b, b + n);
    forn(i, n) if (a[i].first < b[i]) {
        le.pb(i);
    } else {
        ri.pb(i);
    }
    reverse(ri.begin(), ri.end());
    for (int x : le) {
        while (true) {
            int dif = b[x] - a[x].first;
            if (dif == 0) {
                break;
            }
            cleanUp();
            if (ri.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            int ind = ri.back();
            if (ind < x) {
                cout << "NO" << endl;
                return 0;
            }
            int delta = min(dif, a[ind].first - b[ind]);
            ans.pb(mp(mp(a[x].second, a[ind].second), delta));
            a[x].first += delta;
            a[ind].first -= delta;
        }
    }
    cleanUp();
    if (!ri.empty()) {
        cout << "NO" << endl;
        return 0;
    }
    printf("YES\n");
    printf("%d\n", (int)ans.size());
    for (auto p : ans) {
        printf("%d %d %d\n", p.first.first, p.first.second, p.second);
    }
    return 0;
}