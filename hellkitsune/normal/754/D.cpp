#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int from[300000], to[300000];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (to[lhs] != to[rhs]) return to[lhs] < to[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

struct E {
    int pos, id, st;
    E(int pos, int id, int st) : pos(pos), id(id), st(st) {}
    E() {}
};

inline bool cmp(const E &lhs, const E &rhs) {
    if (lhs.pos != rhs.pos) return lhs.pos < rhs.pos;
    return lhs.st < rhs.st;
}

E ev[600000];
int evc = 0;

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) {
        scanf("%d%d", from + i, to + i);
        ++to[i];
    }
    forn(i, n) {
        ev[evc++] = E(from[i], i, 1);
        ev[evc++] = E(to[i], i, 0);
    }
    sort(ev, ev + evc, cmp);
    int bestI = -1;
    int bestRes = 0;
    forn(i, evc) {
        E &e = ev[i];
        if (e.st == 0) {
            q.erase(e.id);
        } else {
            q.insert(e.id);
            while (int(q.size()) > k) {
                q.erase(q.begin());
            }
            if (int(q.size()) == k) {
                int len = to[*q.begin()] - from[e.id];
                if (len > bestRes) {
                    bestRes = len;
                    bestI = i;
                }
            }
        }
    }
    cout << bestRes << endl;
    if (bestI == -1) {
        forn(i, k) printf("%d ", i + 1);
        cout << endl;
        return 0;
    }
    q.clear();
    forn(i, evc) {
        E &e = ev[i];
        if (e.st == 0) {
            q.erase(e.id);
        } else {
            q.insert(e.id);
            while (int(q.size()) > k) {
                q.erase(q.begin());
            }
            if (i == bestI) {
                for (int x : q) {
                    printf("%d ", x + 1);
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}