#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9) + int(1e6);

int n, cnt[2], t;
int a[2][1000005];
vector<int> all;
int d[2000005][2];
bool p[2000005][2], s[2000005][2];

vector<int> sw;
vector<PII> sh;

int main() {
    scanf("%d%d%d%d", &n, cnt, cnt + 1, &t);
    forn(i, 2) forn(j, cnt[i]) {
        scanf("%d", a[i] + j);
    }
    forn(i, 2) a[i][cnt[i]] = INF;
    all.pb(0);
    all.pb(n + 1);
    forn(i, 2) forn(j, cnt[i]) {
        all.pb(a[i][j] - 1);
        all.pb(a[i][j] + 1);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    forn(i, (int)all.size() - 1) {
        forn(j, 2) if (d[i][j] >= 0) {
            int pos = all[i];
            int jj = j ^ 1;
            int wall = *lower_bound(a[jj], a[jj] + cnt[jj], pos);
            if (wall != pos && d[i][jj] < min(d[i][j], t)) {
                d[i][jj] = min(d[i][j], t);
                p[i][jj] = true;
            }
        }
        forn(j, 2) if (d[i][j] >= 0) {
            int pos = all[i];
            int jj = j ^ 1;
            int wall = *lower_bound(a[j], a[j] + cnt[j], pos + 1);
            if (wall != pos + 1) {
                d[i + 1][j] = d[i][j] + all[i + 1] - pos;
                p[i + 1][j] = false;
                s[i + 1][j] = false;
            } else if (d[i][j] >= t) {
                d[i + 1][j] = d[i][j] + all[i + 1] - pos - t;
                p[i + 1][j] = false;
                s[i + 1][j] = true;
            }
        }
    }
    int ed = (int)all.size() - 1;
    forn(j, 2) if (d[ed][j] >= 0) {
        cout << "Yes" << endl;
        while (ed != 0 || j != 0) {
            if (p[ed][j]) {
                j ^= 1;
                sw.pb(all[ed]);
            } else if (s[ed][j]) {
                --ed;
                sh.pb(mp(all[ed] - d[ed][j] + t, j));
            } else {
                --ed;
            }
        }
        sort(sw.begin(), sw.end());
        sort(sh.begin(), sh.end());
        printf("%d\n", (int)sw.size());
        for (int x : sw) printf("%d ", x);
        puts("");
        printf("%d\n", (int)sh.size());
        for (PII x : sh) printf("%d %d\n", x.first, x.second + 1);
        return 0;
    }
    cout << "No" << endl;
    return 0;
}