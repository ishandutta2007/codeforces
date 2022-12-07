#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int t[30];
int f[333][333];

const int dy[8] = {1, 1, 0, -1, -1, -1,  0,  1};
const int dx[8] = {0, 1, 1,  1,  0, -1, -1, -1};

struct S {
    int y, x, dir;

    S(int y, int x, int dir) : y(y), x(x), dir(dir) {}

    inline bool operator < (const S &rhs) const {
        if (y != rhs.y) return y < rhs.y;
        if (x != rhs.x) return x < rhs.x;
        return dir < rhs.dir;
    }

    inline bool operator == (const S &rhs) const {
        return y == rhs.y && x == rhs.x && dir == rhs.dir;
    }
};

vector<S> cur, nx;

int main() {
    cin >> n;
    forn(i, n) cin >> t[i];
    cur.pb(S(155, 155, 0));
    forn(i, n) {
        nx.clear();
        for (S s : cur) {
            int y = s.y;
            int x = s.x;
            forn(j, t[i]) {
                y += dy[s.dir];
                x += dx[s.dir];
                f[y][x] = 1;
            }
            nx.pb(S(y, x, (s.dir + 7) % 8));
            nx.pb(S(y, x, (s.dir + 1) % 8));
        }
        sort(nx.begin(), nx.end());
        nx.erase(unique(nx.begin(), nx.end()), nx.end());
        cur = nx;
    }
    int ans = 0;
    forn(i, 333) forn(j, 333) {
        ans += f[i][j];
    }
    cout << ans << endl;
    return 0;
}