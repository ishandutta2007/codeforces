#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char buf[1234];
map<string, int> ma;
int a[5000][1000];
int op[5000];
int u[5000], v[5000];
int mn[1000], mx[1000];
int val[5000];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%s", buf);
        string s = string(buf);
        ma[s] = i;
        scanf("%s", buf);
        scanf("%s", buf);
        if (buf[0] >= '0' && buf[0] <= '9') {
            op[i] = 0;
            forn(j, m) {
                a[i][j] = buf[j] - '0';
            }
        } else {
            if (buf[0] == '?') {
                u[i] = -1;
            } else {
                u[i] = ma[string(buf)];
            }
            scanf("%s", buf);
            if (buf[0] == 'A') {
                op[i] = 1;
            } else if (buf[0] == 'O') {
                op[i] = 2;
            } else {
                op[i] = 3;
            }
            scanf("%s", buf);
            if (buf[0] == '?') {
                v[i] = -1;
            } else {
                v[i] = ma[string(buf)];
            }
        }
    }
    forn(bit, m) {
        int res[2];
        forn(num, 2) {
            int sum = 0;
            forn(i, n) {
                if (op[i] == 0) {
                    val[i] = a[i][bit];
                } else {
                    int fr, se;
                    if (u[i] == -1) {
                        fr = num;
                    } else {
                        fr = val[u[i]];
                    }
                    if (v[i] == -1) {
                        se = num;
                    } else {
                        se = val[v[i]];
                    }
                    if (op[i] == 1) {
                        val[i] = fr & se;
                    } else if (op[i] == 2) {
                        val[i] = fr | se;
                    } else {
                        val[i] = fr ^ se;
                    }
                }
                sum += val[i];
            }
            res[num] = sum;
        }
        if (res[0] < res[1]) {
            mn[bit] = 0;
            mx[bit] = 1;
        } else if (res[0] > res[1]) {
            mn[bit] = 1;
            mx[bit] = 0;
        } else {
            mn[bit] = 0;
            mx[bit] = 0;
        }
    }
    forn(i, m) printf("%d", mn[i]);
    printf("\n");
    forn(i, m) printf("%d", mx[i]);
    printf("\n");
    return 0;
}