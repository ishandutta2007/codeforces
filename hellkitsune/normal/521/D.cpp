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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int k, n, m;
LL a[100000];
int initA[100000];
int t[100000], ind[100000], b[100000];
bool used[100000];
set<int> ans[100000];
vector<int> v[100000], mul;
int pos[100000], mpos = 0;
int z[100000];
double best[100000];
bool bestz[100000] = {};

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (best[lhs] != best[rhs]) return best[lhs] > best[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

bool cmp(const int &lhs, const int &rhs) {
    return b[lhs] > b[rhs];
}

bool cmp2(const int &lhs, const int &rhs) {
    return t[lhs] < t[rhs];
}

vector<int> tmp;
vector<int> aans;

int main() {
    scanf("%d%d%d", &k, &n, &m);
    REP(i, k) {
        int x;
        scanf("%d", &x);
        initA[i] = a[i] = x;
    }
    REP(i, n) scanf("%d%d%d", t + i, ind + i, b + i), --t[i], --ind[i];
    REP(i, k) z[i] = -1;
    REP(i, k) used[i] = true;
    REP(i, n) if (t[i] == 0) {
        if (b[i] > a[ind[i]] && (z[ind[i]] == -1 || b[z[ind[i]]] < b[i])) {
            z[ind[i]] = i;
            used[ind[i]] = false;
        }
    } else if (t[i] == 1) {
        v[ind[i]].pb(i);
    } else {
        if (b[i] != 1) {
            mul.pb(i);
        }
    }
    sort(mul.begin(), mul.end(), cmp);
    REP(i, k) sort(v[i].begin(), v[i].end(), cmp);
    REP(i, k) pos[i] = 0;
    while (mpos < (int)mul.size() && m) {
        --m;
        ans[ind[mul[mpos]]].insert(mul[mpos]);
        ++mpos;
    }
    REP(i, k) {
        best[i] = 0;
        if (!used[i]) {
            best[i] = b[z[i]] / (double)a[i];
            bestz[i] = true;
        }
        if (!v[i].empty() && (a[i] + b[v[i][0]]) / (double)a[i] > best[i]) {
            best[i] = (a[i] + b[v[i][0]]) / (double)a[i];
            bestz[i] = false;
        }
        if (best[i] > 0.5)
            q.insert(i);
    }
    while (!q.empty()) {
        int cur = *q.begin();
        q.erase(q.begin());
        if (m == 0) {
            if (mpos == 0 || b[mul[mpos - 1]] >= best[cur]) {
                break;
            }
            ans[ind[mul[mpos - 1]]].erase(mul[mpos - 1]);
            --mpos;
        } else {
            --m;
        }
        if (bestz[cur]) {
            a[cur] = b[z[cur]];
            ans[cur].insert(z[cur]);
            used[cur] = true;
        } else {
            a[cur] += b[v[cur][pos[cur]]];
            ans[cur].insert(v[cur][pos[cur]]);
            ++pos[cur];
        }
        bool flag = false;
        best[cur] = 0;
        if (pos[cur] < (int)v[cur].size()) {
            bestz[cur] = false;
            best[cur] = (a[cur] + b[v[cur][pos[cur]]]) / (double)a[cur];
            flag = true;
        }
        if (!used[cur]) {
            int ad = b[z[cur]] - initA[cur];
            if (best[cur] < (a[cur] + ad) / (double)a[cur]) {
                bestz[cur] = true;
                best[cur] = (a[cur] + ad) / (double)a[cur];
                flag = true;
            }
        }
        if (flag) q.insert(cur);
        used[cur] = true;
    }
    REP(i, k) {
        tmp.clear();
        for (int x : ans[i]) tmp.pb(x);
        sort(tmp.begin(), tmp.end(), cmp2);
        for (int x : tmp)
            aans.pb(x);
    }
    printf("%d\n", (int)aans.size());
    REP(i, aans.size())
        printf("%d ", aans[i] + 1);
    printf("\n");
    return 0;
}