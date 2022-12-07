#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL k;
int a, b;
int p[3][3];
int q[3][3];
map<PII, pair<PLL, int> > ma;

int main() {
    cin >> k >> a >> b;
    --a, --b;
    --k;
    forn(i, 3) forn(j, 3) cin >> p[i][j], --p[i][j];
    forn(i, 3) forn(j, 3) cin >> q[i][j], --q[i][j];
    int step = 0;
    LL ascore = 0, bscore = 0;
    if (a != b) {
        if (b == a + 1 || (b == 0 && a == 2)) {
            ++bscore;
        } else {
            ++ascore;
        }
    }
    bool flag = true;
    while (k > 0) {
        if (flag && ma.count(mp(a, b))) {
            flag = false;
            int was = ma[mp(a, b)].second;
            LL pascore = ma[mp(a, b)].first.first;
            LL pbscore = ma[mp(a, b)].first.second;
            LL times = k / (step - was);
            ascore += times * (ascore - pascore);
            bscore += times * (bscore - pbscore);
            k -= times * (step - was);
            continue;
        }
        ma[mp(a, b)] = mp(mp(ascore, bscore), step);
        int na = p[a][b];
        b = q[a][b];
        a = na;
        if (a != b) {
            if (b == a + 1 || (b == 0 && a == 2)) {
                ++bscore;
            } else {
                ++ascore;
            }
        }
        --k;
        ++step;
    }
    cout << ascore << ' ' << bscore << endl;
    return 0;
}