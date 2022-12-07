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

char s[50005];
int n, m;
char q1[7], q2[7];
int a[100000], b[100000], al[100000], bl[100000];
vector<int> v[532000];
map<LL, int> ma;

const int INF = 1e9;

int main() {
    scanf("%s%d", s, &n);
    m = strlen(s);
    REP(i, n) {
        scanf("%s%s", q1, q2);
        al[i] = strlen(q1), bl[i] = strlen(q2);
        a[i] = b[i] = 0;
        REP(j, al[i]) a[i] = a[i] * 27 + q1[j] - 'a' + 1;
        REP(j, bl[i]) b[i] = b[i] * 27 + q2[j] - 'a' + 1;
    }
    REP(i, m) {
        int x = 0;
        REP(j, min(4, m - i)) {
            x = x * 27 + s[i + j] - 'a' + 1;
            v[x].pb(i);
        }
    }
    REP(i, n) {
        if (v[a[i]].empty() || v[b[i]].empty()) {
            printf("-1\n");
            continue;
        }
        if (v[a[i]].size() == v[b[i]].size()) {
            if (a[i] > b[i]) swap(a[i], b[i]), swap(al[i], bl[i]);
        } else if (v[a[i]].size() > v[b[i]].size())
            swap(a[i], b[i]), swap(al[i], bl[i]);
        LL z = (((LL)a[i]) << 25) | b[i];
        if (ma.count(z)) {
            printf("%d\n", ma[z]);
            continue;
        }
        vector<int> &va = v[a[i]], &vb = v[b[i]];
        int ans = INF;
        REP(j, va.size()) {
            int l = 0, r = vb.size() - 1, mid;
            while (l < r) {
                mid = (l + r) >> 1;
                if (vb[mid] < va[j])
                    l = mid + 1;
                else
                    r = mid;
            }
            r = min(l + 4, (int)vb.size() - 1);
            l = max(l - 4, 0);
            for (int k = l; k <= r; ++k) {
                ans = min(ans, max(va[j] + al[i], vb[k] + bl[i]) - min(va[j], vb[k]));
            }
        }
        ma[z] = ans;
        printf("%d\n", ans);
    }
    return 0;
}