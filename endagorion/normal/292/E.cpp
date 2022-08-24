#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

int a[100010], b[100010];

struct TEvent {
    int ast, bst, len;
    int t;
    TEvent(int _ast = 0, int _bst = 0, int _len = 0, int _t = 0)
        : ast(_ast)
        , bst(_bst)
        , len(_len)
        , t(_t)
    {
    }

    bool operator<(const TEvent ev) const {
        return bst < ev.bst;
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &b[i]);
    }
    set<TEvent> evs;
    for (int i = 0; i < N; ++i) {
        evs.insert(TEvent(-1, i, 1, 0));
    }
    for (int i = 0; i < M; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            --x; --y;
            TEvent ev = TEvent(x, y, k, 1);
            set<TEvent>::iterator it = evs.upper_bound(ev);
            --it;
            TEvent inter = *it;
            if (inter.t == 1) {
                evs.erase(it);
                int shift = y - inter.bst;
                if (shift > 0) {
                    evs.insert(TEvent(inter.ast, inter.bst, shift, 1));
                }
                if (inter.len > shift) {
                    evs.insert(TEvent(inter.ast + shift, inter.bst + shift, inter.len - shift, 1));
                }
            }
            it = evs.upper_bound(TEvent(-1, y + k));
            --it;
            inter = *it;
            if (inter.t == 1) {
                evs.erase(it);
                int shift = y + k - inter.bst;
                if (shift > 0) {
                    evs.insert(TEvent(inter.ast, inter.bst, shift, 1));
                }
                if (inter.len > shift) {
                    evs.insert(TEvent(inter.ast + shift, inter.bst + shift, inter.len - shift, 1));
                }
            }
            while (true) {
                it = evs.lower_bound(ev);
                if (it != evs.end() && it->bst < y + k) {
                    evs.erase(it);
                } else {
                    break;
                }
            }
            evs.insert(ev);
        } else {
            int x;
            scanf("%d", &x);
            --x;
            set<TEvent>::iterator it = evs.upper_bound(TEvent(-1, x));
            --it;
            int ans;
            if (it->t == 0) {
                ans = b[it->bst];
            } else {
                ans = a[it->ast + x - it->bst];
            }
            printf("%d\n", ans);
        }
    }

	return 0;
}