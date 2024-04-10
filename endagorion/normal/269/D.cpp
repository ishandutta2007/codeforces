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
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

struct TSeg {
    int l, r, y;

    TSeg(int _l = 0, int _r = 0, int _y = 0)
        : l(_l)
        , r(_r)
        , y(_y)
    {
    }
};

struct TEv {
    int x, id;
    bool open;

    TEv(int _x = 0, int _id = 0, bool _open = false)
        : x(_x)
        , id(_id)
        , open(_open)
    {
    }

    bool operator<(const TEv &ev) const {
        if (x != ev.x) {
            return x < ev.x;
        }
        return open < ev.open;
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, T;
    cin >> N >> T;
    vector<TSeg> segs(N);
    vector<TEv> evs;
    for (int i = 0; i < N; ++i) {
        cin >> segs[i].y >> segs[i].l >> segs[i].r;        
    }
    segs.pb(TSeg(-1000000000, 1000000000, 0));
    segs.pb(TSeg(-1000000000, 1000000000, T));
    for (int i = 0; i < N + 2; ++i) {
        evs.pb(TEv(segs[i].l, i, true));
        evs.pb(TEv(segs[i].r, i, false));
    }
    sort(all(evs));
    vector< int > up(N + 2, -1), down(N + 2, -1);
    vector< vector<int> > eDown(N + 2);
    set< pair<int, int> > s;
    for (size_t i = 0; i < evs.size(); ++i) {
        int id = evs[i].id, y = segs[id].y;
        if (evs[i].open) {
            set< pair<int, int> >::iterator it = s.lower_bound(mp(y, 0));
            if (it != s.end()) {
                up[id] = it->second;
                down[it->second] = id;
            }
            if (it != s.begin()) {
                --it;
                up[it->second] = id;
                down[id] = it->second;
            }
            s.insert(mp(y, id));
        } else {
            set< pair<int, int> >::iterator it = s.lower_bound(mp(y, 0));
            if (down[id] != -1) {
                eDown[id].pb(down[id]);
            }
            if (up[id] != -1) {
                eDown[up[id]].pb(id);
            }
            s.insert(mp(y, id));
            s.erase(mp(y, id));
            if (down[id] != -1) {
                up[down[id]] = -1;
            }
            if (up[id] != -1) {
                down[up[id]] = -1;
            }
        }
    }

    vector< pair<int, int> > ls(N + 2);
    for (int i = 0; i < N + 2; ++i) {
        ls[i] = mp(segs[i].y, i);
    }

    sort(rall(ls));
    vector<int> ans(N + 2);
    ans[N + 1] = 2000000000;
    for (int i = 0; i + 1 < N + 2; ++i) {
        int x = ls[i].second;
        for (size_t j = 0; j < eDown[x].size(); ++j) {
            int y = eDown[x][j];
            ans[y] = max(ans[y], min(ans[x], min(segs[x].r, segs[y].r) - max(segs[x].l, segs[y].l)));
        }
    }
    cout << ans[N] << '\n';

	return 0;
}