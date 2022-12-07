#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
string s[100];
string res, cur;
bool used[100][100] = {};

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};
const char dc[4] = {'L', 'R', 'U', 'D'};

void dfs(int y, int x) {
    used[y][x] = true;
    if (s[y][x] == 'F') {
        res = cur;
    }
    forn(dir, 4) {
        int yy = y + dy[dir];
        if (yy < 0 || yy >= n) continue;
        int xx = x + dx[dir];
        if (xx < 0 || xx >= m) continue;
        if (used[yy][xx]) continue;
        if (s[yy][xx] == '*') continue;
        cur += dc[dir];
        dfs(yy, xx);
        cur.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    forn(i, n) cin >> s[i];
    dfs(0, 0);
    int y, x;
    y = x = 1;
    bool lr = 0, ud = 0;
    for (char c : res) {
        forn(_, 2) {
            int yy = y;
            int xx = x;
            if (c == 'L') --xx;
            else if (c == 'R') ++xx;
            else if (c == 'U') --yy;
            else ++yy;
            if (lr && (c == 'L' || c == 'R')) {
                c = (c == 'L' ? 'R' : 'L');
            }
            if (ud && (c == 'U' || c == 'D')) {
                c = (c == 'U' ? 'D' : 'U');
            }
            cout << c << endl;
            int ay, ax;
            cin >> ay >> ax;
            if (ay == -1) {
                return 0;
            }
            if (ay == yy && ax == xx) {
                x = xx;
                y = yy;
                break;
            }
            if (c == 'L' || c == 'R') {
                lr = 1;
            } else {
                ud = 1;
            }
        }
    }
    return 0;
}