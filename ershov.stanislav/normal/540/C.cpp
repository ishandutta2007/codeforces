#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

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

const int INF = 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, m, r1, c1, r2, c2;
char b[555][555];
bool used[555][555];

bool flag = false;

void dfs(int r, int c) {
    if (r == r2 && c == c2) {
        flag = true;
    }
    if (b[r][c] == 'X' && (r != r1 || c != c1)) {
        return;
    }
    if (used[r][c]) {
        return;
    }
    used[r][c] = true;
    if (r > 0) dfs(r - 1, c);
    if (r < n - 1) dfs(r + 1, c);
    if (c > 0) dfs(r, c - 1);
    if (c < m - 1) dfs(r, c + 1);
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %s", b[i]);
    }
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    r1--, c1--, r2--, c2--;

    dfs(r1, c1);

    int cnt = 0;
    if (r2 > 0 && b[r2 - 1][c2] != 'X') {
        cnt++;
    }
    if (r2 < n - 1 && b[r2 + 1][c2] != 'X') {
        cnt++;
    }
    if (c2 > 0 && b[r2][c2 - 1] != 'X') {
        cnt++;
    }
    if (c2 < m - 1 && b[r2][c2 + 1] != 'X') {
        cnt++;
    }

    if (cnt > 1 || (abs(r1 - r2) + abs(c1 - c2) <= 1 && cnt > 0) || (cnt > 0 && r1 == r2 && c1 == c2) || (b[r2][c2] == 'X' && (r1 != r2 || c1 != c2))) {
        flag = flag;
    } else {
        flag = false;
    }

    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}