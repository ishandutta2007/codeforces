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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef DEBUG
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

using namespace std;

int n, m;
int a[7], b[25];
int powers[7];
string s[7];
bool used[11 * 11 * 11 * 11 * 11 + 100][50][25];

bool dfs(int v, int mask, int k) {
    if (used[v][mask][k]) {
        return false;
    } else {
        used[v][mask][k] = true;
    }
    if (k == m) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != v / powers[i] % 11) {
                flag = false;
            }
        }
        return flag;
    } else {
        for (int i = 0; i < n; i++) {
            if ((v / powers[i]) % 11 > a[i]) {
                return false;
            }
            if ((v / powers[i]) % 11 + (m - k + 1) / 2 < a[i]) {
                return false;
            }
        }
        if (b[k] == 0) {
            if (dfs(v, 0, k + 1)) {
                for (int r = 0; r < n; r++) {
                    s[r].pb('.');
                }
                return true;
            }
        } else if (b[k] == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int v2 = 0;
                    for (int k = n - 1; k >= 0; k--) {
                        v2 *= 11;
                        if (k >= i && k <= j) {
                            v2 += v / powers[k] % 11 + ((mask & (1 << k)) == 0);
                        } else {
                            v2 += v / powers[k] % 11;
                        }
                    }
                    if (dfs(v2, (1 << (j + 1)) - (1 << i), k + 1)) {
                        for (int r = 0; r < n; r++) {
                            if (r >= i && r <= j) {
                                s[r].pb('*');
                            } else {
                                s[r].pb('.');
                            }
                        }
                        return true;
                    }
                }
            }
        } else if (b[k] == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    for (int i2 = j + 2; i2 < n; i2++) {
                        for (int j2 = i2; j2 < n; j2++) {
                            int v2 = 0;
                            for (int k = n - 1; k >= 0; k--) {
                                v2 *= 11;
                                if ((k >= i && k <= j) || (k >= i2 && k <= j2)) {
                                    v2 += v / powers[k] % 11 + ((mask & (1 << k)) == 0);
                                } else {
                                    v2 += v / powers[k] % 11;
                                }
                            }
                            if (dfs(v2, (1 << (j + 1)) - (1 << i) + (1 << (j2 + 1)) - (1 << i2) , k + 1)) {
                                for (int r = 0; r < n; r++) {
                                    if ((r >= i && r <= j) || (r >= i2 && r <= j2)) {
                                        s[r].pb('*');
                                    } else {
                                        s[r].pb('.');
                                    }
                                }
                                return true;
                            }
                        }
                    }
                }
            }
        } else if (b[k] == 3) {
            int v2 = 0;
            for (int i = n - 1; i >= 0; i--) {
                v2 *= 11;
                if (i % 2 == 0) {
                    v2 += v / powers[i] % 11 + ((mask & (1 << i)) == 0);
                } else {
                    v2 += v / powers[i] % 11;
                }
            }
            if (dfs(v2, 21, k + 1)) {
                for (int r = 0; r < n; r++) {
                    if (r % 2 == 0) {
                        s[r].pb('*');
                    } else {
                        s[r].pb('.');
                    }
                }
                return true;
            }
        }
    }
    return false;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int j = 0; j < m; j++) {
        scanf("%d", b + j);
    }
    powers[0] = 1;
    for (int i = 1; i < 7; i++) {
        powers[i] = powers[i - 1] * 11;
    }
    dfs(0, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            printf("%c", s[i][j]);
        }
        printf("\n");
//        cout << s[i] << endl;
    }
    return 0;
}