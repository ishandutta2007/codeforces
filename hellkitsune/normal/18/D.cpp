#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

unsigned int d[5002][65] = {};
int x[5000];
bool ev[5000];
int mt[5000];
string s;
int k, n;
const unsigned int one = 1;
int p[2015][620], cnt[2015];
int ans[620] = {}, ac = 1;

void upd(int v1, int v2, int inc = -1) {
    if (inc != -1) {
        REP(i, 65) d[5001][i] = d[v2][i];
        if (d[5001][inc >> 5] + (one << (inc & 31)) < d[5001][inc >> 5]) {
            for (int j = (inc >> 5) + 1; ; ++j) {
                if (d[5001][j] + one > d[5001][j])
                    break;
                d[5001][j] += one;
            }
        }
        d[5001][inc >> 5] += (one << (inc & 31));
        v2 = 5001;
    }
    bool flag = true;
    for (int i = 64; i >= -1; --i) {
        if (i == -1 || d[v1][i] > d[v2][i]) {
            flag = false;
            break;
        } else if (d[v1][i] < d[v2][i]) {
            break;
        }
    }
    if (flag) REP(i, 65)
        d[v1][i] = d[v2][i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        cin >> s >> x[i];
        ev[i] = s[0] == 'w';
    }
    REP(i, n) {
        mt[i] = -1;
        if (ev[i]) {
            for (int j = i + 1; j < n; ++j) if (x[j] == x[i] && !ev[j]) {
                mt[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        upd(5000, i);
        if (mt[i])
            upd(mt[i], 5000, x[i]);
    }
    cnt[0] = 1, p[0][0] = 1;
    for (int i = 1; i < 2015; ++i) {
        cnt[i] = cnt[i - 1];
        REP(j, cnt[i]) p[i][j] = p[i - 1][j] << 1;
        p[i][cnt[i]] = 0;
        REP(j, cnt[i]) if (p[i][j] > 9) {
            p[i][j] -= 10;
            ++p[i][j + 1];
        }
        if (p[i][cnt[i]]) ++cnt[i];
    }
    for (int i = 0; i < 2015; ++i) if (d[5000][i >> 5] & (one << (i & 31))) {
        ac = max(ac, cnt[i]);
        REP(j, cnt[i]) ans[j] += p[i][j];
        ans[ac] = 0;
        REP(j, ac) if (ans[j] > 9) {
            ans[j] -= 10;
            ++ans[j + 1];
        }
        if (ans[ac]) ++ac;
    }
    for (int i = ac - 1; i >= 0; --i)
        cout << ans[i];
    cout << endl;
    return 0;
}