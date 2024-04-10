#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int D = 100000;

struct S {
    int p, t, ind;
    S(int p, int t, int ind) : p(p), t(t), ind(ind) {}
    inline bool operator < (const S &rhs) const {
        return p <= rhs.p;
    }
};

int n, w, h;
vector<S> a, b;
int res[100000];
deque<int> v[200005];
int finX[100000], finY[100000];

void solve(vector<S> &a, vector<S> &b) {
    for (S s : a) {
        v[D + s.p - s.t].pb(s.ind);
    }
    for (S s : b) {
        v[D + s.p - s.t].push_front(s.ind);
        v[D + s.p - s.t].pop_back();
    }
    for (S s : a) {
        res[v[D + s.p - s.t].front()] = s.ind;
        v[D + s.p - s.t].pop_front();
    }
}

int main() {
    scanf("%d%d%d", &n, &w, &h);
    forn(i, n) {
        int g, p, t;
        scanf("%d%d%d", &g, &p, &t);
        if (g == 1) {
            a.pb(S(p, t, i));
            finX[i] = p;
            finY[i] = h;
        } else {
            b.pb(S(p, t, i));
            finX[i] = w;
            finY[i] = p;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    memset(res, -1, sizeof res);
    solve(a, b);
    solve(b, a);
    forn(i, n) {
        assert(res[i] >= 0 && res[i] < n);
        printf("%d %d\n", finX[res[i]], finY[res[i]]);
    }
    return 0;
}