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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    vector<int> v;
    int mx = 0;
};

int n;
int a[100000], c[100000], rev[100000];
vector<S> s;
vector<int> v;
int ROOT = 300;
vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", a + i, c + i), --a[i];
    REP(i, n) rev[a[i]] = i;
    s.pb(S());
    v.pb(0);
    REP(i, n) {
        int j = 0, vj = v[0];
        while (j < (int)v.size() - 1 && s[vj].mx < a[i] && (int)s[vj].v.size() <= c[i]) {
            c[i] -= (int)s[vj].v.size();
            ++j;
            vj = v[j];
        }
        int ind = min(c[i], (int)s[vj].v.size());
        REP(k, ind) if (s[vj].v[k] > a[i]) {
            ind = k;
            break;
        }
        s[vj].v.resize(s[vj].v.size() + 1);
        for (int k = (int)s[vj].v.size() - 1; k > ind; --k) {
            s[vj].v[k] = s[vj].v[k - 1];
        }
        s[vj].v[ind] = a[i];
        s[vj].mx = max(s[vj].mx, a[i]);
        if ((int)s[vj].v.size() == ROOT * 2) {
            vector<int> z;
            for (int q = ROOT; q < 2 * ROOT; ++q) z.pb(s[vj].v[q]);
            int mxz = 0;
            REP(q, ROOT) mxz = max(mxz, z[q]);
            s[vj].v.resize(ROOT);
            s[vj].mx = 0;
            REP(q, ROOT) s[vj].mx = max(s[vj].mx, s[vj].v[q]);
            int vs = (int)v.size();
            s.pb(S());
            s.back().v = z;
            s.back().mx = mxz;
            v.pb(0);
            for (int q = vs; q > j + 1; --q) v[q] = v[q - 1];
            v[j + 1] = vs;
        }
    }
    for (int i : v) for (int x : s[i].v) {
        ans.pb(rev[x] + 1);
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}