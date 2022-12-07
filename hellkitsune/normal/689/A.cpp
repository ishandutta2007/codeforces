#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

set<PII> se;
map<int, PII> ma;
int a[4][3] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
int n;
string s;
vector<PII> all;

int main() {
    REP(i, 3) REP(j, 3) se.insert(mp(i, j));
    se.insert(mp(3, 1));
    REP(i, 4) REP(j, 3) ma[a[i][j]] = mp(i, j);
    cin >> n >> s;
    REP(i, n) {
        int x = s[i] - '0';
        all.pb(ma[x]);
    }
    REP(i, 4) REP(j, 3) if (se.count(mp(i, j))) {
        if (mp(i, j) == all[0]) continue;
        PII cur = mp(i, j);
        bool ok = true;
        for (int i = 1; i < (int)all.size(); ++i) {
            cur.first += all[i].first - all[i - 1].first;
            cur.second += all[i].second - all[i - 1].second;
            if (!se.count(cur)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}