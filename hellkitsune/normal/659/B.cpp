#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char buf[15];
vector<pair<int, string> > a[10000];

inline bool cmp(const pair<int, string> &lhs, const pair<int, string> &rhs) {
    return lhs.first > rhs.first;
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        int reg, pts;
        scanf("%s%d%d", buf, &reg, &pts), --reg;
        a[reg].pb(mp(pts, string(buf)));
    }
    REP(i, m) {
        sort(a[i].begin(), a[i].end(), cmp);
        if ((int)a[i].size() > 2 && a[i][1].first == a[i][2].first) {
            printf("?\n");
        } else {
            printf("%s %s\n", a[i][0].second.c_str(), a[i][1].second.c_str());
        }
    }
    return 0;
}