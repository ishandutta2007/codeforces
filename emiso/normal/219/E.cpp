#include <bits/stdc++.h>

using namespace std;

int n, m, t, id, loc[1000100], used[1000100];
map<int, int> seg;
set<pair<int, int>> rep;

void put(int x, pair<int, int> segm) {
    int len = -segm.first, st = segm.second;

    assert(rep.count(segm));
    rep.erase(segm);
    if(x > st) rep.insert({-((x-st-1)/2), st});
    if(x < seg[st]) rep.insert({-((seg[st]-x-1)/2), x + 1});

    if(st < x) {
        if(seg[st] > x) seg[x+1] = seg[st];
        seg[st] = x-1;
    } else {
        if(seg[st] > x) seg[x+1] = seg[st];
        seg.erase(st);
    }
}

void rem(int x) {
    if(!used[x-1] && !used[x+1]) { /// merge
        int st = prev(seg.upper_bound(x))->first;
        assert(seg[st] == x - 1);
        rep.erase({-((x-st-1)/2), st});

        int ed = seg[x+1];
        rep.erase({-((ed-x-1)/2), x+1});
        seg.erase(x+1);

        seg[st] = ed;
        rep.insert({-((ed-st)/2), st});

    } else if(!used[x-1]) { /// left
        int st = prev(seg.upper_bound(x))->first;
        assert(seg[st] == x - 1);
        rep.erase({-((x-st-1)/2), st});
        rep.insert({-((x-st)/2), st});
        seg[st] = x;
    } else if(!used[x+1]) { /// rite
        int ed = seg[x+1];
        rep.erase({-((ed-x-1)/2), x+1});
        seg.erase(x+1);
        seg[x] = ed;
        rep.insert({-((ed-x)/2), x});
    } else { /// alone
        seg[x] = x;
        rep.insert({0, x});
    }
}

int main() {
    scanf("%d %d", &n, &m);
    used[0] = used[n+1] = 1;

    seg.insert({1, n});
    rep.insert({-((n-1)/2), 1});

    while(m--) {
        scanf("%d %d", &t, &id);
        if(t == 1) {
            int l = (used[1] ? -1 : seg[1] - 1), mid = -rep.begin()->first, r = (used[n] ? -1 : n-seg.rbegin()->first);
            if(l >= mid || r > mid) {
                if(l >= r) {
                    put(1, {-((seg[1]-1)/2), 1});
                    loc[id] = 1;
                } else {
                    put(n, {-((n-seg.rbegin()->first)/2), seg.rbegin()->first});
                    loc[id] = n;
                }
            } else {
                auto tt = *rep.begin();
                int len = -tt.first, st = tt.second;
                put(st + len, tt);
                loc[id] = st + len;
            }
            used[loc[id]] = 1;
            printf("%d\n", loc[id]);
        } else if(t == 2) {
            rem(loc[id]);
            used[loc[id]] = 0;
        } else assert(false);
    }

    return 0;
}