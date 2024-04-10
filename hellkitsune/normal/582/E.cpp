#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[555];
int len, n;
int a[22], b[22], c[22], d[22], e[22];
int z[4][22];
int fin = 0;
map<PII, vector<int> > ma;
int mt[555];
vector<int> pos;
const int MOD = 1e9 + 7;

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

inline void modSub(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

int main() {
    scanf("%s", s + 1);
    s[0] = '(';
    len = strlen(s);
    s[len] = ')';
    ++len;
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d%d%d", a + i, b + i, c + i, d + i, e + i);
    REP(i, n) z[0][i] = a[i], z[1][i] = b[i], z[2][i] = c[i], z[3][i] = d[i];
    REP(i, n) if (e[i]) fin |= 1 << i;
    REP(i, len) if ((s[i] >= 'A' && s[i] <= 'D') || (s[i] >= 'a' && s[i] <= 'd') || s[i] == '?') {
        if (i && s[i - 1] == ')') continue;
        vector<int> v(1 << n, 0);
        REP(va, 4) REP(val, 2) {
            if (!(s[i] == '?' || (val == 0 && s[i] == 'A' + va) || (val == 1 && s[i] == 'a' + va))) continue;
            REP(mask, 1 << n) {
                bool ok = true;
                REP(j, n) if ((z[va][j] ^ val) != ((mask & (1 << j)) > 0)) {
                    ok = false;
                    break;
                }
                if (ok) ++v[mask];
            }
        }
        //REP(i, 1 << n) cout << v[i] << ' ';
        //cout << endl;
        if (len == 1) {
            ma[mp(i, i)] = v;
        } else {
            ma[mp(i - 1, i + 1)] = v;
        }
    }
    //cout << endl;
    REP(i, len) mt[i] = -1;
    REP(i, len) if (s[i] == '(') {
        pos.pb(i);
    } else if (s[i] == ')') {
        mt[pos.back()] = i;
        pos.pop_back();
    }
    for (int llen = 4; llen <= len; ++llen) {
        REP(i, len) if (mt[i] != -1 && mt[i] - i + 1 == llen) {
            vector<int> &u = ma.find(mp(i + 1, mt[i + 1]))->second;
            int j = mt[i + 1] + 2;
            vector<int> &v = ma.find(mp(j, mt[j]))->second;
            vector<int> res(1 << n, 0), res2(1 << n, 0);
            --j;
            if (s[j] != '|') {
                REP(i, n) REP(j, 1 << n) if (!(j & (1 << i))) {
                    modAdd(u[j], u[j | (1 << i)]);
                    modAdd(v[j], v[j | (1 << i)]);
                }
                REP(i, 1 << n) res[i] = (LL)u[i] * v[i] % MOD;
                for (int i = n - 1; i >= 0; --i) REP(j, 1 << n) if (!(j & (1 << i))) {
                    modSub(u[j], u[j | (1 << i)]);
                    modSub(v[j], v[j | (1 << i)]);
                    modSub(res[j], res[j | (1 << i)]);
                }
            }
            //REP(z, 1 << n) cout << res[z] << ' ';
            //cout << endl;
            if (s[j] != '&') {
                REP(i, n) REP(j, 1 << n) if (j & (1 << i)) {
                    modAdd(u[j], u[j ^ (1 << i)]);
                    modAdd(v[j], v[j ^ (1 << i)]);
                }
                REP(i, 1 << n) res2[i] = (LL)u[i] * v[i] % MOD;
                for (int i = n - 1; i >= 0; --i) REP(j, 1 << n) if (j & (1 << i)) {
                    modSub(res2[j], res2[j ^ (1 << i)]);
                }
            }
            //REP(z, 1 << n) cout << res2[z] << ' ';
            //cout << endl << endl;
            REP(z, 1 << n) modAdd(res[z], res2[z]);
            ma[mp(i, mt[i])] = res;
        }
    }
    vector<int> &res = ma.find(mp(0, len - 1))->second;
    cout << res[fin] << endl;
    return 0;
}