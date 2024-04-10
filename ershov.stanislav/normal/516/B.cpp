#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int n, m;

char s[2222][2222];
int cnt[2222][2222], all = 0;
    queue<pair<int, int> > q;

inline int get_cnt(int i, int j) {
    int ans = 0;
    if (i > 0 && s[i - 1][j] == '.') {
        ans++;
    }
    if (i < n-1 && s[i + 1][j] == '.') {
        ans++;
    }
    if (j > 0 && s[i][j - 1] == '.') {
        ans++;
    }
    if (j < m-1 && s[i][j + 1] == '.') {
        ans++;
    }
    return ans;
}

void delete_ij(int i, int j) {
    if (i > 0) {
        cnt[i - 1][j] --;
        if (cnt[i - 1][j] == 1) {
            q.push(mp(i-1, j));
        }
    }
    if (i < n-1) {
        cnt[i + 1][j] --;
        if (cnt[i + 1][j] == 1) {
            q.push(mp(i+1, j));
        }
    }
    if (j > 0) {
        cnt[i][j - 1] --;
        if (cnt[i][j - 1] == 1) {
            q.push(mp(i, j - 1));
        }
    }
    if (j < m-1) {
        cnt[i][j + 1] --;
        if (cnt[i][j + 1] == 1) {
            q.push(mp(i, j + 1));
        }
    }
}

int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) if (s[i][j] == '.') {
            all++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[i][j] = get_cnt(i, j);
            if (cnt[i][j] == 1) {
                q.push(mp(i, j));
            }
        }
    }
    while (q.size()) {
        pair<int, int> cur = q.front();
        int i = cur.fs, j = cur.sc;
        q.pop();
        if (cnt[cur.fs][cur.sc] == 1 && s[i][j] == '.') {
//        cout << i << ' ' << j << endl;
            int i2, j2;

            bool flag = false;

            if (i > 0 && s[i - 1][j] == '.' && !flag) {
                i2 = i-1;
                j2 = j;
                s[i][j] = 'v';
                s[i2][j2] = '^';
                flag = true;
            }
            if (i < n-1 && s[i + 1][j] == '.' && !flag) {
                i2 = i+1;
                j2 = j;
                s[i][j] = '^';
                s[i2][j2] = 'v';
                flag = true;
            }
            if (j > 0 && s[i][j - 1] == '.' && !flag) {
                i2 = i;
                j2 = j-1;
                s[i][j] = '>';
                s[i2][j2] = '<';
                flag = true;
            }
            if (j < m-1 && s[i][j + 1] == '.' && !flag) {
                i2 = i;
                j2 = j+1;
                s[i][j] = '<';
                s[i2][j2] = '>';
                flag = true;
            }

            cnt[i][j] = 0;
            cnt[i2][j2] = 0;
            delete_ij(i, j);
            delete_ij(i2, j2);
            all -= 2;
        }
    }
//        for (int i = 0; i < n; i++) {
//            printf("%s\n", s[i]);
//        }
    if (all != 0) {
        cout << "Not unique" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            printf("%s\n", s[i]);
        }
    }
    return 0;
}